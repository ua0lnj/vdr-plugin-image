/*
 * Image plugin to VDR (C++)
 *
 * (C) 2004-2011 Andreas Brachold    <vdr07 at deltab.de>
 * (C) 2003 Kai Tobias Burwieck <kai at burwieck.net>
 *
 * based on MP3/MPlayer plugin to VDR (C++)
 * (C) 2001,2002 Stefan Huelswitt <huels at iname.com>
 *
 * This code is distributed under the terms and conditions of the
 * GNU GENERAL PUBLIC LICENSE. See the file COPYING for details.
 *
 */

#include <ctype.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "data.h"
#include "data-image.h"
#include "list.h"

#include <vdr/tools.h>

// ----------------------------------------------------------------

const char *g_szMountScript = "mount.sh";

char *AddPath(const char *dir, const char *filename)
{
  int l = strlen(dir);
  char *name = MALLOC(char, l + strlen(filename) + 2);
  if(name)
	{
    strcpy(name, dir);
    name[l] = '/';
    strcpy(name + l + 1, filename);
  } else {
    esyslog("imageplugin: ERROR: no memory for filename");
	}
    return name;
}

class cFileExt : public cListObject
{
	char * m_szExt;
protected:
	void clean() 		{ if(Ext()) free(m_szExt);m_szExt=0;}
public:
	cFileExt() 	{ m_szExt = 0; }
	virtual ~cFileExt() { clean(); }

	cFileExt(cFileExt& x) //Copy-Ctor
	{
		if(x.Ext())
		{
		   m_szExt = MALLOC(char, strlen(x.m_szExt)+1);
		   strcpy(m_szExt,x.m_szExt);
		}
		else m_szExt = 0;
	}
	const char* Ext() const   { return m_szExt; }
	
	const char* Set(const char* sz) 	
	{ 
		const char *f = sz;
		for(;*sz != 0 && *sz == ' ';++sz); 		//Skip leading whitespace
		for(f = sz;*f != 0 && *f != ' ';++f);   //Find end of item \0 or ' ' 

		clean(); //Prevebt double assign

		if(f - sz > 0)	// Store founded item
		{
			   m_szExt = MALLOC(char, f - sz + 1);
			   strncpy(m_szExt,sz,f - sz);
			   *(m_szExt + (f - sz)) = '\0';
		}
		return f;
	}
};

class cFileExtList : public cList<cFileExt>
{
public:
	cFileExtList(const char* szExtList) {
		const char* sz = szExtList;
		while(*sz != 0)
		{
			cFileExt ext;
			sz = ext.Set(sz);
			if(ext.Ext())
				Add(new cFileExt(ext)); // Add copy
		};
	}
	
	virtual ~cFileExtList()
	{
	
	}
};

		
// -- cScanDir --------------------------------------------------------------

bool cScanDir::ScanDir(cFileSource * src, const char *subdir, eScanType type,
		       const char *spec, const char *excl, bool recursiv)
{
  bool result = true;
  char *cmd = 0, *dir = 0, *s = 0, *e = 0, tc;

  switch (type)
	{
	default:
	case stFile:
    tc = 'f';
    break;
	case stDir:
    tc = 'd';
    break;
	}
  if(subdir)
  	asprintf(&dir, "%s/%s", src->BaseDir(), subdir);
  else
	  asprintf(&dir, "%s", src->BaseDir());
  // If is'nt set a filter use this a default
	if(stFile == type && (0 == spec || 0>= strlen(spec)))	
		spec = "*.jpg *.jpeg *.jif *.jiff *.tif *.tiff *.gif *.bmp *.png *.pnm *.mps";
	// Check if filter is set build complex include find ( -iname "*.jpg" -o -iname "*.jpeg" -o .. )
  if(stFile == type && spec)	
	{
    	cFileExtList list(spec); //Splitt *.jpg *.jpeg
   		
		cFileExt *src = list.First(); 
		while(src) //Loop throw all found item 
		{
			char* sn;
		
			if(!s)  //open bracket
				asprintf(&s, " \\( ");

			asprintf(&sn, "%s-iname \"%s\" ",s,QuoteString(src->Ext()));
			if(s) free(s);
			s = sn;
			
	    	src = list.Next(src);			
			if(src) //follow ext
			{
				char* sn;
				asprintf(&sn, "%s-o ",s);
				free(s);
				s = sn;
			}
		}
		if(s) // close bracket
		{
			char* sn;
			asprintf(&sn, "%s\\)",s);
			free(s);
			s = sn;
		}
	}
	// Check if filter is set build complex exclude find  -not ( -iname "*.jpg" -o -iname "*.jpeg" -o .. )
  if(stFile == type && excl) {
    cFileExtList list(excl); //Splitt *.jpg *.jpeg
   		
		cFileExt *src = list.First(); 
		while(src) //Loop throw all found item 
		{
			char* en;

			if(!e)  //open bracket
				asprintf(&e, "-not \\( ");

			asprintf(&en, "%s-iname \"%s\" ",e,QuoteString(src->Ext()));
			if(e) free(e);
			e = en;
			
	    	src = list.Next(src);			
			if(src) //follow ext
			{
				char* en;
				asprintf(&en, "%s-o ",e);
				free(e);
				e = en;
			}
		}
		if(e) // close bracket
		{
			char* en;
			asprintf(&en, "%s\\)",e);
			free(e);
			e = en;
		}
	}
#if 0
  asprintf(&cmd, "find \"%s\" -follow -type %c %s %s %s 2>/dev/null | sort -df",
             QuoteString(dir), tc, s?s:"", e?e:"", recursiv?"":"-maxdepth 1");
#else
  asprintf(&cmd, "find \"%s\" -follow -type %c %s %s %s 2>/dev/null | sort -df | grep -v \"/\\.\"",
             QuoteString(dir), tc, s?s:"", e?e:"", recursiv?"":"-maxdepth 1");
#endif
  //fprintf(stderr,"%s\n",cmd);
  cReadLine l;
  FILE *p = popen(cmd, "r");
  if(p) {
    int len = strlen(dir);
    char *s;
    while((s = l.Read(p)) != 0) {
      char *ss = strstr(s, dir);
      if(ss) {
        s = ss + len;
        if(*s == '/')
  				s++;
    }
    if(*s)
      DoItem(src, subdir, s);
    }
    pclose(p);
  }
  else
  	result = false;

  free(cmd);
  free(dir);
  free(s);
  free(e);
  return result;
}

char *cScanDir::QuoteString(const char *str)
{
  static char *nstr = 0;

  free(nstr);
  nstr = MALLOC(char, strlen(str) * 2);
  char *p = nstr;
  while(*str)
	{
	    switch (*str)
		{
		case '$':	// dollar
		case '\\':	// backslash
		case '\"':	// double quote
		case '`':	// back tick
		    *p++ = '\\';
		    // fall through
		default:
		    *p++ = *str++;
		    break;
		}
	}
  *p = 0;
  return nstr;
}

// -- cDirItem --------------------------------------------------------------

cDirItem::cDirItem(cFileSource * src, const char *subdir, const char *name,
		   const eItemType type)
{
  Source = src;
  Subdir = subdir ? strdup(subdir) : 0;
  Name = name ? strdup(name) : 0;
  Type = type;
}

cDirItem::~cDirItem()
{
  free(Name);
  free(Subdir);
}

char *cDirItem::Path(void)
{
  char *path;
  if(Subdir)
  	path = AddPath(Subdir, Name);
  else
	  path = strdup(Name);
  return path;
}

// -- cDirList --------------------------------------------------------------

bool cDirList::Load(cFileSource * src, const char *subdir)
{
  bool res = false;
  Clear();
  if(subdir)
    Add(new cDirItem(src, subdir, "..", itParent));
  itype = itDir;
  if(ScanDir(src, subdir, stDir, 0, 0, false)) {
    itype = itFile;
    if(ScanDir(src, subdir, stFile, src->Include(), 0, false))
		res = true;
	}
  return res;
}

void cDirList::DoItem(cFileSource * src, const char *subdir, const char *name)
{
  Add(new cDirItem(src, subdir, name, itype));
}



// -- cFileSource --------------------------------------------------------------

cFileSource::cFileSource(void)
{
  browsedir = browseparent = 0;
  basedir = description = include = 0;
  useCount = 0;
  needsmount = false;
}

cFileSource::cFileSource(const char *Basedir, const char *Description,
			 const bool NeedsMount, const char *Include)
{
  browsedir = browseparent = 0;
  basedir = description = include = 0;
  useCount = 0;
  Set(Basedir, Description, NeedsMount, Include);
}

cFileSource::~cFileSource()
{
  ClearRemember();
  free(basedir);
  free(description);
  free(include);
}

void cFileSource::Set(const char *Basedir, const char *Description,
		      const bool NeedsMount, const char *Include)
{
  free(basedir);
  basedir = strdup(Basedir);
  free(description);
  description = strdup(Description);
  free(include);
  include = Include ? strdup(Include) : 0;
  needsmount = NeedsMount;
}

char *cFileSource::BuildName(const char *filename)
{
  return AddPath(basedir, filename);
}

void cFileSource::SetRemember(const char *dir, const char *parent)
{
  ClearRemember();
  if(dir)
    browsedir = strdup(dir);
  if(parent)
    browseparent = strdup(parent);
}

void cFileSource::ClearRemember(void)
{
  free(browsedir);
  browsedir = 0;
  free(browseparent);
  browseparent = 0;
}

bool cFileSource::GetRemember(char *&dir, char *&parent)
{
  dir = parent = 0;
  if(browsedir) {
    if(browseparent)
      parent = strdup(browseparent);
    dir = strdup(browsedir);
    return true;
  }
  return false;
}

bool cFileSource::Parse(char *s)
{
  char base[256], des[256], incl[256];
  int needsmount, n;
  if((n =
    sscanf(s, "%255[^;];%255[^;];%d;%255[^;]", base, des, &needsmount,
           incl)) >= 3)
  {
    char *base2 = skipspace(stripspace(base));
    Set(base2, skipspace(stripspace(des)), needsmount != 0,
      n > 3 ? skipspace(stripspace(incl)) : 0);

    // do some checking of the basedir and issue a warning if apropriate
    if(access(base2, R_OK)) {
      esyslog("imageplugin: WARNING: source base %s not found/permission denied",base2);
    } 
    else {
      struct stat64 ds;
      if(lstat64(base2, &ds)) {
			    esyslog("imageplugin: WARNING: can't stat source base %s",base2);
      } 
      else {
        if(S_ISLNK(ds.st_mode)) {
          esyslog("imageplugin: WARNING: source base %s is a symbolic link",base2);
			    } 
        else if(!S_ISDIR(ds.st_mode)) {
				    esyslog("imageplugin: WARNING: source base %s is not a directory",base2);
				}
			}
		}
    return true;
	}
  return false;
}

bool cFileSource::Action(eAction act)
{
  static const char *str[] = { "mount", "unmount", "eject", "status" };

  char *cmd = 0;
  asprintf(&cmd, "%s %s %s", g_szMountScript, str[act], basedir);
  bool res = (system(cmd) == 0);
  free(cmd);
  return res;
}

bool cFileSource::Mount(void)
{
  bool res = false;
  if(needsmount && (res = Action(acMount)))
    ClearRemember();
  return res;
}

bool cFileSource::Unmount(void)
{
  bool res = false;
  if(needsmount) {

    theSlideShow.Remove(this);
    
    if(!useCount && (res = Action(acUnmount)))
      ClearRemember();
	}
  return res;
}

bool cFileSource::Eject(void)
{
  bool res = false;
  if(needsmount) {
  
    theSlideShow.Remove(this);
    
    if(!useCount && (res = Action(acEject)))
      ClearRemember();
	}
  return res;
}

bool cFileSource::Status(void)
{
  if(needsmount)
    return Action(acStatus);
  return true;
}

// -- cFileSources --------------------------------------------------------------

bool cFileSources::Load(const char *filename, bool dummy)
{
  if(cConfig < cFileSource >::Load(filename, true)) {
    SetSource(First());
    return true;
  }
  return false;
}

cFileSource *cFileSources::FindSource(const char *filename)
{
  cFileSource *src = First();
  while(src) {
    if(startswith(filename, src->BaseDir()))
  		return src;
    src = Next(src);
	}
  return 0;
}

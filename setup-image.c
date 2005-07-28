/*
 * Image plugin to VDR (C++)
 *
 * (C) 2004-2005 Andreas Brachold    <vdr04-at-deltab.de>
 * based on (C) 2003 Kai Tobias Burwieck      <kai-at-burwieck.net>
 *
 * based on MP3/MPlayer plugin to VDR (C++)
 * (C) 2001,2002 Stefan Huelswitt <huels-at-iname.com>
 *
 *
 * This code is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 * Or, point your browser to http://www.gnu.org/copyleft/gpl.html
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <vdr/tools.h>
#include <vdr/config.h>
#include "setup-image.h"
#include "i18n.h"

cImageSetup ImageSetup;

const int cImageSetup::m_cSSMin = 2;
const int cImageSetup::m_cSSMax = 300;


const int cImageSetup::m_cnMinBorderHeight = 0;
const int cImageSetup::m_cnMaxBorderHeight = 480/2; //(Half NTSC)

const int cImageSetup::m_cnMinBorderWidth = 0;
const int cImageSetup::m_cnMaxBorderWidth = 720/2;  //(Half NTSC/PAL)

// --- cImageSetup -----------------------------------------------------------

cImageSetup::cImageSetup(void)

{
  m_bSlideShow = 0;
  m_nSSsec = 10;
  strncpy(m_szTempDir, "/tmp/image", sizeof(m_szTempDir));
#if VDRVERSNUM < 10307
  m_bShowDate = 1;
#endif
  m_bAutoRepeat = 0;
  m_bShowNumbers = 1;
#if VDRVERSNUM >= 10308
  m_bLiveAudio = 0;
#endif 
  m_bHousekeeping = 1;

  m_nBorderHeight = 16;
  m_nBorderWidth = 16;
}

#define ParseInteger(szTitle,nValue,nMin,nMax) \
  if(!strcasecmp(szName, szTitle))             \
  {                                            \
    nValue = atoi(szValue);                    \
    if(nValue < nMin) nValue = nMin;           \
    if(nValue > nMax) nValue = nMax;           \
  } 


bool cImageSetup::SetupParse(const char *szName, const char *szValue)
{
       ParseInteger("SlideShow",     m_bSlideShow,0,1)
  else ParseInteger("SSsec",         m_nSSsec,m_cSSMin,m_cSSMax)
  else ParseInteger("BorderHeight",  m_nBorderHeight,m_cnMinBorderHeight,m_cnMaxBorderHeight)
  else ParseInteger("BorderWidth",   m_nBorderWidth,m_cnMinBorderWidth,m_cnMaxBorderWidth)
#if VDRVERSNUM < 10307
  else ParseInteger("ShowDate",      m_bShowDate,0,1)
#endif    
  else ParseInteger("AutoRepeat",    m_bAutoRepeat,0,1)
  else ParseInteger("ShowNumbers",   m_bShowNumbers,0,1)
#if VDRVERSNUM >= 10308
  else ParseInteger("LiveAudio",     m_bLiveAudio,0,1)
#endif   
  else ParseInteger("Housekeeping",  m_bHousekeeping,0,1)
  else if(!strcasecmp(szName, "TempDir")) {
        strn0cpy(m_szTempDir,szValue,sizeof(m_szTempDir));
  }
  else return false;
  return true;
}

// --- cMenuSetupImage --------------------------------------------------------
void cMenuSetupImage::Store(void)
{
  ImageSetup = m_tmpSetup;
  SetupStore("SlideShow",               ImageSetup.m_bSlideShow);
  SetupStore("SSsec",                   ImageSetup.m_nSSsec);
  SetupStore("TempDir",                 ImageSetup.m_szTempDir);
#if VDRVERSNUM < 10307
  SetupStore("ShowDate",                ImageSetup.m_bShowDate);
#endif
  SetupStore("AutoRepeat",              ImageSetup.m_bAutoRepeat);
  SetupStore("ShowNumbers",             ImageSetup.m_bShowNumbers);
#if VDRVERSNUM >= 10308
  SetupStore("LiveAudio",               ImageSetup.m_bLiveAudio);
#endif   
  SetupStore("Housekeeping",            ImageSetup.m_bHousekeeping);
  SetupStore("BorderHeight",            ImageSetup.m_nBorderHeight);
  SetupStore("BorderWidth",             ImageSetup.m_nBorderWidth);
}

cMenuSetupImage::cMenuSetupImage(void)
: m_tmpSetup(ImageSetup)
{
  SetSection(tr("Image"));

  Add(new cMenuEditBoolItem(tr("SlideShow ?"),                    
        &m_tmpSetup.m_bSlideShow,    
        tr("no"), tr("yes")));

  Add(new cMenuEditIntItem (tr("Slide duration (sec)"),           
        &m_tmpSetup.m_nSSsec,        
        cImageSetup::m_cSSMin, cImageSetup::m_cSSMax));

  Add(new cMenuEditBoolItem(tr("Repeat SlideShow"),               
        &m_tmpSetup.m_bAutoRepeat,   
        tr("no"), tr("yes")));

#if VDRVERSNUM < 10307
  Add(new cMenuEditBoolItem(tr("Show Filedate on OSD"),           
        &m_tmpSetup.m_bShowDate,     
        tr("no"), tr("yes")));
#endif

  Add(new cMenuEditBoolItem(tr("Show Numbers on index image"),    
        &m_tmpSetup.m_bShowNumbers,
        tr("no"), tr("yes")));

#if VDRVERSNUM >= 10308
  Add(new cMenuEditBoolItem(tr("Live Audio from primary Device"), 
        &m_tmpSetup.m_bLiveAudio,
        tr("no"), tr("yes")));
#endif   

  Add(new cMenuEditStrItem (tr("Directory with temporary files"), 
        m_tmpSetup.m_szTempDir,sizeof(m_tmpSetup.m_szTempDir), 
        "abcdefghijklmopqrstuvwxyz/-"));

  Add(new cMenuEditBoolItem(tr("Remove temporary files"),
        &m_tmpSetup.m_bHousekeeping,  
        tr("no"), tr("yes")));

  Add(new cMenuEditIntItem (tr("Border for Underscan (Height)"),
        &m_tmpSetup.m_nBorderHeight,
        cImageSetup::m_cnMinBorderHeight, cImageSetup::m_cnMaxBorderHeight));

  Add(new cMenuEditIntItem (tr("Border for Underscan (Width)"),
        &m_tmpSetup.m_nBorderWidth,
        cImageSetup::m_cnMinBorderWidth, cImageSetup::m_cnMaxBorderWidth));

}





void cImageSetup::SetEnv(void) const
{
  unsigned int i;
  struct cImageCommandEnv { 
    const char* szEnv;  
    const char* szValue;
  } nEnvironTable [] =
  {
    {"ASPECT_RATIO",Setup.VideoFormat?"16:9":"4:3"}, // Get from DVB-Setup
    {"CONVERT_TEMPDIR",m_szTempDir},            
  };

  for(i=0;i < sizeof(nEnvironTable)/sizeof(*nEnvironTable);++i)
  {
    if(nEnvironTable[i].szValue) { 
      if(0!= setenv(nEnvironTable[i].szEnv, nEnvironTable[i].szValue,1))
        esyslog("imageplugin: can't setenv '%s = %s'", nEnvironTable[i].szEnv, nEnvironTable[i].szValue);
    }
    else { 
      if(0!= unsetenv(nEnvironTable[i].szEnv))
        esyslog("imageplugin: can't unsetenv '%s'", nEnvironTable[i].szEnv);
    }
  }
}

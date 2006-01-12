/*
 * Image plugin to VDR (C++)
 *
 * (C) 2004-2006 Andreas Brachold    <anbr at users.berlios.de>
 * based on (C) 2003 Kai Tobias Burwieck      <kai-at-burwieck.net>
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

#include <vdr/config.h>
#include "i18n.h"

const tI18nPhrase Phrases[] = {
  { "Image", // English
    "Bilder", // German
    "", // Slovenian
    "Immagine", // Italian
    "Beelden", // Dutch
    "Imagens", // Portuguese
    "Images", // French
    "", // Norwegian
    "Kuvat",    // Finnish
    "", // Polish
    "Im�genes",  // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "�����������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "A Image Viewer plugin", // English
    "Ein Bildbetrachter Plugin", // German
    "", // Slovenian
    "Un visore di immagine plugin", // Italian
    "Een Kijker van het Beeld plugin", // Dutch
    "Um visor da imagem plugin", // Portuguese
    "Visualisateur d'images", // French
    "", // Norwegian
    "Katso valokuvia ruudullasi",  // Finnish
    "", // Polish
    "Un espectador de la imagen plugin", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "������ ��� ��������� �����������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Image browser", // English
    "Bilder Verzeichnisanzeige", // German
    "Image navigator", // Slovenian
    "Browser di immagine", // Italian
    "Browser van het beeld", // Dutch
    "Browser da imagem", // Portuguese
    "Navigateur images", // French
    "", // Norwegian
    "Kuvat - selain", // Finnish
    "", // Polish
    "Browser de la imagen", // Spanish
    "Image endiksi fakelon", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "�������� ����� � �������������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Image source", // English
    "Bilder-Datentr�ger", // German
    "Image izvor", // Slovenian
    "Fonte di immagine", // Italian
    "De bron van het beeld", // Dutch
    "Fonte da imagem", // Portuguese
    "Source images", // French
    "", // Norwegian
    "Kuvat - l�hteet", // Finnish
    "", // Polish
    "Fuente de la imagen", // Spanish
    "Pigi Image", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "��������(source)", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Parent", // English
    "Zur�ck", // German
    "Nazaj", // Slovenian
    "precursore", // Italian
    "voorloper", // Dutch
    "precursor", // Portuguese
    "", // French
    "", // Norwegian
    "Takaisin", // Finnish
    "", // Polish
    "Predecesor", // Spanish
    "Piso", // Greek
    "Tillbaka", // Swedish
    "", // Romanian
    "", // Hugarian
    "Anterior", // Catalan
    "�����", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Select", // English
    "Ausw�hlen", // German
    "Izberi", // Slovenian
    "Prescelto", // Italian
    "Selecteer", // Dutch
    "Seleto", // Portuguese
    "S�lectionner", // French
    "", // Norwegian
    "Valitse", // Finnish
    "", // Polish
    "Seleccionar", // Spanish
    "Epilogi", // Greek
    "V�lj", // Swedish
    "", // Romanian
    "", // Hugarian
    "Escollir", // Catalan
    "�������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Play",
    "Wiedergabe",
    "Predvajaj",
    "Riproduci",
    "Weergeven",
    "",// TODO
    "Lecture",
    "",// TODO
    "Toista",
    "Odtworzenie",
    "Reproducir",
    "�����������",
    "Spela upp",
    "Redare",
    "Lej�tsz�s",
    "Reproduir",
    "���������������",
    "Start",
    "Start",
    "Afspil",
  },
  { "Back",
    "Zur�ck",
    "Nazaj",
    "Indietro",
    "Terug",
    "Voltar",
    "Retour",
    "Tilbake",
    "Takaisin",
    "Wstecz",
    "Retornar",
    "����",
    "Tillbaka",
    "�napoi",
    "Vissza",
    "Retornar",
    "�����",
    "Nazad",
    "Tagasi",
    "Tilbage",
  },
  { "Error scanning directory!", // English
    "Fehler beim Lesen des Verzeichnisses!", // German
    "Napaka pri pregledovanju direktorija!", // Slovenian
    "Indice di esame di errori!", // Italian
    "Het aftastenfolder van de fout!", // Dutch
    "Diret�rio da explora��o do erro!", // Portuguese
    "Erreur de parcours du r�pertoire!", // French
    "", // Norwegian
    "Hakemiston selaus ep�onnistui!", // Finnish
    "", // Polish
    "�Error al leer una carpeta!", // Spanish
    "Lathos stin sarosi tou fakelou!", // Greek
    "Kunde inte l�sa katalogen!", // Swedish
    "", // Romanian
    "", // Hugarian
    "Error al llegir una carpeta!", // Catalan
    "������ ������ ��������� ����������!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Data medium", // English
    "Datentr�ger", // German
    "Izvor", // Slovenian
    "Mezzo di dati", // Italian
    "Het middel van gegevens", // Dutch
    "Meio de dados", // Portuguese
    "Source", // French
    "", // Norwegian
    "L�hde", // Finnish
    "", // Polish
    "Medio de datos", // Spanish
    "Pigi", // Greek
    "K�lla", // Swedish
    "", // Romanian
    "", // Hugarian
    "Or�gen", // Catalan
    "��������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Mount", // English
    "Einbinden", // German
    "Priklopi", // Slovenian
    "supporto", // Italian
    "Zet op", // Dutch
    "Montagem", // Portuguese
    "Monter", // French
    "", // Norwegian
    "Kiinnit�", // Finnish
    "", // Polish
    "Montaje", // Spanish
    "Sindesi", // Greek
    "Montera", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "����������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Unmount", // English
    "Aush�ngen", // German
    "Izklopi", // Slovenian
    "smonti", // Italian
    "unmount", // Dutch
    "unmount", // Portuguese
    "D�monter", // French
    "", // Norwegian
    "Irrota", // Finnish
    "", // Polish
    "Unmount", // Spanish
    "Aposindesi", // Greek
    "Avmontera", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "��������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Selected data medium is not mounted!", // English
    "Ausgew�hlter Datentr�ger ist nicht eingebunden!", // German
    "Izbran izvor ni prikljucen!", // Slovenian
    "Il mezzo di dati selezionato non � montato!", // Italian
    "Het geselecteerde gegevensmiddel wordt niet opgezet!", // Dutch
    "O meio de dados selecionado n�o � montado!", // Portuguese
    "Source s�lectionn�e non mont�e!", // French
    "", // Norwegian
    "Valittua l�hdett� ei ole kiinnitetty!", // Finnish
    "", // Polish
    "�El origen deseado no est� montado!", // Spanish
    "Epilegmeni Pigi den ine sindemeni!", // Greek
    "Den valda k�llan �r inte monterad!", // Swedish
    "", // Romanian
    "", // Hugarian
    "l'Origen sel.leccionat no est� muntat!", // Catalan
    "��������� �������� �� ���������!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Mount succeeded", // English
    "Einbinden erfolgreich", // German
    "Priklop izveden", // Slovenian
    "Il supporto � riuscito", // Italian
    "Zet volgend op", // Dutch
    "Montagem sucedida", // Portuguese
    "Montage r�ussi", // French
    "", // Norwegian
    "Kiinnitt�minen onnistui", // Finnish
    "", // Polish
    "mount correcto", // Spanish
    "I sindesi petixe", // Greek
    "Monteringen lyckades", // Swedish
    "", // Romanian
    "", // Hugarian
    "mount correcte", // Catalan
    "����������� ������ �������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Mount failed!", // English
    "Einbinden fehlgeschlagen!", // German
    "Napaka pri priklopu!", // Slovenian
    "Il supporto si guasta!", // Italian
    "Zet ontbroken op!", // Dutch
    "A montagem falha!", // Portuguese
    "Echec du montage!", // French
    "", // Norwegian
    "Kiinnitt�minen ep�onnistui!", // Finnish
    "", // Polish
    "�No he podido montar!", // Spanish
    "I sindesi apetixe!", // Greek
    "Monteringen misslyckades!", // Swedish
    "", // Romanian
    "", // Hugarian
    "No he pogut muntar!", // Catalan
    "������ �����������!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Unmount succeeded!", // English
    "Aush�ngen erfolgreich!", // German
    "Izklop izveden!", // Slovenian
    "Smonti riuscito!", // Italian
    "Volgende Unmount!", // Dutch
    "Unmount sucedido!", // Portuguese
    "D�montage r�ussi!", // French
    "", // Norwegian
    "Irrottaminen onnistui!", // Finnish
    "", // Polish
    "�xito al unmount", // Spanish
    "I aposindesi itan epitixisi!", // Greek
    "Avmonteringen lyckades!", // Swedish
    "", // Romanian
    "", // Hugarian
    "unmount amb �xit!", // Catalan
    "���������� ������ �������!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Unmount failed!", // English
    "Aush�ngen fehlgeschlagen!", // German
    "Napaka pri izklopu!", // Slovenian
    "Smonti venuto a mancare!", // Italian
    "Ontbroken Unmount!", // Dutch
    "Unmount falhado!", // Portuguese
    "Echec du d�montage!", // French
    "", // Norwegian
    "Irrottaminen ep�onnistui!", // Finnish
    "", // Polish
    "�No puedo desmontar!", // Spanish
    "I aposindesi den itan epitixis!", // Greek
    "Avmonteringen misslyckades!", // Swedish
    "", // Romanian
    "", // Hugarian
    "No puc desmontar!",
    "������ ����������!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Eject failed!", // English
    "Auswerfen fehlgeschlagen!", // German
    "Napaka pri izmetu!", // Slovenian
    "Espella venuto a mancare!", // Italian
    "Werp ontbroken uit!", // Dutch
    "Ejete falhado!", // Portuguese
    "Echec de l'�jection!", // French
    "", // Norwegian
    "Avaaminen ep�onnistui!", // Finnish
    "", // Polish
    "�No puedo expulsar!", // Spanish
    "I apovoli apetixe!", // Greek
    "Mata ut!", // Swedish
    "", // Romanian
    "", // Hugarian
    "No puc expulsar!", // Catalan
    "������ ������� �����!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Select picture via key 1..9!", // English
    "Bildauswahl �ber Taste 1..9!", // German
    "", // Slovenian
    "Selezioni l'immagine via il tasto 1..9!", // Italian
    "Selecteer beeld via knoop 1..9!", // Dutch
    "Selecione o retrato atrav�s da tecla 1..9!", // Portuguese
    "Selectionner l'image (touches 1..9)!", // French
    "", // Norwegian
    "Valitse kuva n�pp�imill� 1..9!", // Finnish
    "", // Polish
    "�Seleccione el cuadro v�a el bot�n 1..9!", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "����� ������������ ��� ������ ������ 1..9!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Building slide show...", // English
    "Erzeuge Diavorf�hrung...", // German
    "", // Slovenian
    "Proiezione di diapositive Della Costruzione...", // Italian
    "De Show van de Dia van de bouw...", // Dutch
    "Mostra De Corredi�a Do Edif�cio...", // Portuguese
    "Contruction du SlideShow...", // French
    "", // Norwegian
    "Laaditaan diaesityst�..", // Finnish
    "", // Polish
    "Demostraci�n De Diapositiva Del Edificio...", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "�������� ���������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Scanning directory...", // English
    "Durchsuche Verzeichnis...", // German
    "", // Slovenian
    "Indice di esame...", // Italian
    "De folder van het aftasten...", // Dutch
    "Diret�rio da explora��o...", // Portuguese
    "Scannage du r�pertoire...", // French
    "", // Norwegian
    "Selataan hakemistoa...", // Finnish
    "", // Polish
    "Leyendo las carpetas..", // Spanish
    "", // Greek
    "S�ker igenom katalog...", // Swedish
    "", // Romanian
    "", // Hugarian
    "Revisant les carpetes..", // Catalan
    "������� ����������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "No Files!", // English
    "Keine Dateien!", // German
    "", // Slovenian
    "Nessun lime!", // Italian
    "Geen dossiers!", // Dutch
    "Nenhumas Limas!", // Portuguese
    "Pas de fichiers !", // French
    "", // Norwegian
    "Ei tiedostoja!", // Finnish
    "", // Polish
    "�Ningunos Archivos!", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "������ �� �������!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Slide show", // English
    "Diavorf�hrung", // German
    "", // Slovenian
    "Proiezione di diapositive", // Italian
    "De show van de dia", // Dutch
    "Mostra de corredi�a", // Portuguese
    "Projection de diapositives", // French
    "", // Norwegian
    "K�yt� diaesityst�", // Finnish
    "", // Polish
    "Demostraci�n de diapositiva", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "��������?", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Slide duration (sec)", // English
    "Anzeigedauer (Sek)", // German
    "", // Slovenian
    "Faccia scorrere la durata (sec)", // Italian
    "De duur van de dia (seconde)", // Dutch
    "Deslize a dura��o (segundo)", // Portuguese
    "Dur�e entre les images (Sec)", // French
    "", // Norwegian
    "Dian esitysaika (s)", // Finnish
    "", // Polish
    "Resbale la duraci�n (sec)", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "����� ����������� (���)", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Directory with temporary files", // English
    "Verzeichnis mit tempor�ren Dateien", // German
    "", // Slovenian
    "Indice con le lime provvisorie", // Italian
    "Folder met tijdelijke dossiers", // Dutch
    "Diret�rio com limas provis�rias", // Portuguese
    "R�pertoire temporaire", // French
    "", // Norwegian
    "V�liaikaistiedostot", // Finnish
    "", // Polish
    "Directorio con los ficheros temporales", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "¼� ����������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Repeat slide show", // English
    "Wiederholung der Diavorf�hrung", // German
    "", // Slovenian
    "Ripeti la proiezione di diapositive", // Italian
    "Herhaal diashow", // Dutch
    "Repita a mostra de corredi�a", // Portuguese
    "R�p�ter le SlideShow", // French
    "", // Norwegian
    "Diaesityksen uudelleentoisto", // Finnish
    "", // Polish
    "Repita la demostraci�n de diapositiva", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "������ ���������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Show numbers on index image", // English
    "Zeige Zahlen im Indexbild", // German
    "", // Slovenian
    "Mostri i numeri sull'immagine di indice", // Italian
    "Toon aantallen op indexbeeld", // Dutch
    "Mostre n�meros na imagem do �ndice", // Portuguese
    "Afficher nombre sur la page d'index", // French
    "", // Norwegian
    "N�yt� numerot indeksikuvassa", // Finnish
    "", // Polish
    "Demuestre los n�meros en imagen del �ndice", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "�������� ������ � �������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Live Audio from primary Device", // English
    "Live Audio vom prim�ren Ger�t", // German
    "", // Slovenian
    "Audio in tensione dal dispositivo primario", // Italian
    "Leef Audio van primair Apparaat", // Dutch
    "�udio vivo do dispositivo preliminar", // Portuguese
    "Audio en direct", // French
    "", // Norwegian
    "Live-��ni ensisijaiselta sovittimelta", // Finnish
    "", // Polish
    "Audio vivo del dispositivo primario", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "������������ ��������(Live) �������� �������������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Convert...", // English
    "Wandle...", // German
    "", // Slovenian
    "Convertito...", // Italian
    "Zet om...", // Dutch
    "Converso...", // Portuguese
    "Convertion...", // French
    "", // Norwegian
    "Konvertoi...", // Finnish
    "", // Polish
    "Convertido...", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "�����������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },  
  { "Zoom", // English
    "Vergr��ere", // German
    "", // Slovenian
    "Zoom", // Italian
    "Gezoem", // Dutch
    "Zumbido", // Portuguese
    "Zoom", // French
    "", // Norwegian
    "Suurenna", // Finnish
    "", // Polish
    "Zumbido", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "����������(Zoom)", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },  
  { "Execute", // English
    "Ausf�hren", // German
    "", // Slovenian
    "Esegua", // Italian
    "Voer uit", // Dutch
    "Execute", // Portuguese
    "Executer", // French
    "", // Norwegian
    "Suorita", // Finnish
    "", // Polish
    "Ejec�tese", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "���������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },  
  { "Operation failed", // English
    "Vorgang fehlgeschlagen", // German
    "", // Slovenian
    "Il funzionamento viene a mancare", // Italian
    "Ontbroken verrichting", // Dutch
    "A opera��o falhou", // Portuguese
    "Op�ration non r�ussie", // French
    "", // Norwegian
    "Toiminto ep�onnistui", // Finnish
    "", // Polish
    "La operaci�n fall�", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "�������� �����������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Image couldn't load", // English
    "Konnte Bild nicht lesen", // German
    "", // Slovenian
    "L'immagine non ha potuto caricare", // Italian
    "Het beeld kon niet laden", // Dutch
    "A imagem n�o podia carregar", // Portuguese
    "Impossible de charger l'image", // French
    "", // Norwegian
    "Kuvan lukeminen ep�onnistui", // Finnish
    "", // Polish
    "La imagen no pod�a cargar", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "������ ������ �����", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Script execution failed", // English
    "Scriptausf�hrung fehlgeschlagen", // German
    "", // Slovenian
    "L'esecuzione dello scritto � venuto a mancare", // Italian
    "Ontbroken de uitvoering van het manuscript", // Dutch
    "A execu��o do certificado falhou", // Portuguese
    "Impossible d'ex�cuter le script", // French
    "", // Norwegian
    "Skriptin suoritus ep�onnistui", // Finnish
    "", // Polish
    "La ejecuci�n de la escritura fall�", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "������ ���������� �������!", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Remove temporary files", // English
    "L�sche tempor�re Dateien", // German
    "", // Slovenian
    "Rimuova le lime provvisorie", // Italian
    "Verwijder tijdelijke dossiers", // Dutch
    "Remova as limas provis�rias", // Portuguese
    "Effacer les fichiers temporaires", // French
    "", // Norwegian
    "Tyhjenn� v�liaikaistiedostot", // Finnish
    "", // Polish
    "Quite los ficheros temporales", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "�������� tmp ������", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Border for Underscan (Height)", // English
    "Rand f�r Underscan (H�he)", // German
    "", // Slovenian
    "Bordo per Underscan (altezza)", // Italian
    "Grens voor Underscan (Hoogte)", // Dutch
    "Beira para Underscan (altura)", // Portuguese
    "Fronti�re pour Underscan (taille)", // French
    "", // Norwegian
    "Reunuksen korkeus keskitykselle", // Finnish
    "", // Polish
    "Frontera para Underscan (altura)", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Border for Underscan (Width)", // English
    "Rand f�r Underscan (Breite)", // German
    "", // Slovenian
    "Bordo per Underscan (larghezza)", // Italian
    "Grens voor Underscan (Breedte)", // Dutch
    "Beira para Underscan (largura)", // Portuguese
    "Fronti�re pour Underscan (largeur)", // French
    "", // Norwegian
    "Reunuksen leveys keskitykselle", // Finnish
    "", // Polish
    "Frontera para Underscan (anchura)", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Show exif informations from image", // English
    "Zeigt Exif Informationen zum Bild", // German
    "", // Slovenian
    "Mostri le informazioni del exif dall'immagine", // Italian
    "Toon exif informatie van beeld", // Dutch
    "Mostre a informa��o do exif da imagem", // Portuguese
    "Montrez l'information d'exif de l'image", // French
    "", // Norwegian
    "", // Finnish
    "", // Polish
    "Demuestre la informaci�n del exif de la imagen", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Could not parse exif maker note!", // English
    "Konnte Exif Erstellungsanmerkung nicht analysieren!", // German
    "", // Slovenian
    "Non ha potuto analizzare la nota del creatore del exif!", // Italian
    "Kon exif maker geen nota ontleden!", // Dutch
    "N�o podia analisar gramaticalmente a nota do fabricante do exif!", // Portuguese
    "N'a pas pu analyser la note de fabricant d'exif !", // French
    "", // Norwegian
    "", // Finnish
    "", // Polish
    "�No pod�a analizar la nota del fabricante del exif!", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { "Could not load exif data from image!", // English
    "Konnte Exif Daten nicht vom Bild laden!", // German
    "", // Slovenian
    "Non ha potuto caricare i dati del exif dall'immagine!", // Italian
    "Kon exif geen gegevens van beeld laden!", // Dutch
    "N�o podia carregar dados do exif da imagem!", // Portuguese
    "N'a pas pu charger des donn�es d'exif de l'image !", // French
    "", // Norwegian
    "", // Finnish
    "", // Polish
    "�No pod�a cargar datos del exif de imagen!", // Spanish
    "", // Greek
    "", // Swedish
    "", // Romanian
    "", // Hugarian
    "", // Catalan
    "", // Russian
    "", // Hrvatski
    "", // Eesti
    "", // Dansk
  },
  { NULL }
};

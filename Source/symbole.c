//###############################################################################
/** 
  Die Funktion fordert den Nutzer zur Eingabe einer Ganzzahl auf. 
  Liegt die Nutzereingabe nicht im Wertebereich wird die Eingabe wiederholt.
  
  @param  symbole Zeiger auf Zeichenkette aus der Ziffern exhtrahiert werden
  
  @return Zeiger auf Zeichenkette mit Ziffern
**/
//###############################################################################
char *extrahiere_ziffern(char *symbole)
{
  char *ziffern = (char *) calloc(strlen(symbole) + 1, sizeof(char));
  for (unsigned int i = 0; i < strlen(symbole); i++)
  {
    if (isdigit(symbole[i]))
      ziffern[strlen(ziffern)] = symbole[i];
  }
  return ziffern;
}

//###############################################################################
/** 
  Die Funktion fordert den Nutzer zur Eingabe einer Ganzzahl auf. 
  Liegt die Nutzereingabe nicht im Wertebereich wird die Eingabe wiederholt.
  
  @param  zeichen Zeichenkette von der Teilbereich gebildet wird
  @param  start Beginn des Teilbereich
  @param  laenge  Länge des Teilbereich

  @return Liefert ermittelten Teilbereich als Zeiger auf Zeichenkette
**/
//###############################################################################
char *extrahiere_bereich(char *zeichen, unsigned int start, unsigned int laenge)
{
  char *bereich = (char *) calloc(laenge + 1, sizeof(char));

  if (start + laenge <= strlen(zeichen))
  {
    for (unsigned int i = start; i < start + laenge; i++)
      bereich[strlen(bereich)] = zeichen[i];
  }

  return bereich;
}


//###############################################################################
/** 
  Berechnet aus der übergebenen Zeichenkette die wiederholte Quersumme bis zum 
  einstelligen Ergebnis und liefert dieses als Ganzzahl zurück.
  
  @param  symbole Beschriftung der Eingabeaufforderung  

  @return Liefert den Wert der Quersumme als Ganzzahl
**/
//###############################################################################
int berechne_euro_quersumme(char *symbole)
{
  int summe = 0;
  char puffer[10];
  
  for (unsigned int i = 0; i < strlen(symbole); i++)
  {
    summe += (47 < symbole[i] && symbole[i] < 58) ? symbole[i] - 48 : symbole[i];
  }

  return (1 < snprintf(puffer, 10, "%i", summe)) ? berechne_euro_quersumme(puffer) : summe;
}

//###############################################################################
/** 
  Schreibt für das übergebene Bitmuster die Fehlernachrichten in die Standard-
  ausgabe. 
  
  @param  fehler  Bitmuster als Ausdruck enthaltener Fehler
**/
//###############################################################################
void schreibe_euro_fehler(unsigned int fehler)
{
  char *ausgabe[] = {
    "Die Seriennummer ist zu leer.",
    "Die Seriennummer ist zu kurz.",
    "Die Seriennummer ist zu lang.",
    "Erstes Symbol ist kein Buchstabe.",
    "Das Laenderkennzeichen ist falsch.",
    "Kleinbuchstaben sind enthalten.",
    "Ziffernfolge unterbrochen.",
  };

  int laenge = sizeof(ausgabe) / sizeof(ausgabe[0]);
  
  for (int i = 0; i < laenge; i++)
  {
    unsigned int bit = pow(2, i);
    if (bit == (bit & fehler))
    {
      printf("\n%s", ausgabe[i]);
    }
  }
}

//###############################################################################
/** 
  Validiert übergebene Zeichenkette auf die Repräsentation einer gültigen 
  EURO-Seriennummer.
  Enthaltene Fehler werden als Bitmuster erfasst und zurückgegeben.
  
  @param  nummer  Minimum des definierten Wertebereiches
  @param  maximum Beschriftung der Eingabeaufforderung  

  @return Liefert enthaltene Fehler als Bitmuster
**/
//###############################################################################
unsigned int validiere_euro_nummer(char *nummer, unsigned int maximum)
{
  unsigned int ergebnis = 0;
  unsigned int laenge = strlen(nummer);
  
  ergebnis |= (laenge == 0) ? 1 : 0;
  ergebnis |= (laenge < maximum) ? 2 : 0;
  ergebnis |= (laenge > maximum) ? 4 : 0;
  
  if (0 < laenge) {
  
    ergebnis |= isalpha(nummer[0]) ? 0 : 8;

    ergebnis |= validiere_euro_symbol(nummer[0]) ? 0 : 16;

    for (unsigned int i = 1; i < laenge && i < maximum; i++)
    {
      ergebnis |= isdigit(nummer[i]) ? 0 : 64;
    }
    
    for (unsigned int i = 0; i < laenge && i < maximum; i++)
    {
      ergebnis |= islower(nummer[i]) ? 32 : 0;
    }
  }

  return ergebnis;
}

//###############################################################################
/** 
  Füllt eine Struktur-Liste vom Typ 'nzb' und liefert den Zeiger auf die Struktur
  
  @return Liefert Daten als Zeiger auf Struktur von NZB
**/
//###############################################################################
struct nzb *daten(void)
{
  struct nzb *kennung = (struct nzb *) calloc(20, sizeof(struct nzb));

  kennung[0].rest = 0;
  kennung[0].code = 'Z';
  strcpy(kennung[0].land, "Belgien");
  
  kennung[1].rest = 1;
  kennung[1].code = 'Y';
  strcpy(kennung[1].land, "Griechenland");
  
  kennung[2].rest = 2;
  kennung[2].code = 'X';
  strcpy(kennung[2].land, "Deutschland");
  
  kennung[3].rest = 4;
  kennung[3].code = 'V';
  strcpy(kennung[3].land, "Spanien");
  
  kennung[4].rest = 5;
  kennung[4].code = 'U';
  strcpy(kennung[4].land, "Frankreich");
  
  kennung[5].rest = 6;
  kennung[5].code = 'T';
  strcpy(kennung[5].land, "Irland");
  
  kennung[6].rest = 7;
  kennung[6].code = 'S';
  strcpy(kennung[6].land, "Italien");
  
  kennung[7].rest = 1;
  kennung[7].code = 'P';
  strcpy(kennung[7].land, "Niederlande");
  
  kennung[8].rest = 3;
  kennung[8].code = 'N';
  strcpy(kennung[8].land, "Österreich");
  
  kennung[9].rest = 4;
  kennung[9].code = 'M';
  strcpy(kennung[9].land, "Portugal");
  
  kennung[10].rest = 5;
  kennung[10].code = 'L';
  strcpy(kennung[10].land, "Finnland");
  
  kennung[11].rest = 0;
  kennung[11].code = 'H';
  strcpy(kennung[11].land, "Slowenien");
  
  kennung[12].rest = 1;
  kennung[12].code = 'G';
  strcpy(kennung[12].land, "Zypern");
  
  kennung[13].rest = 2;
  kennung[13].code = 'F';
  strcpy(kennung[13].land, "Malta");
  
  kennung[14].rest = 3;
  kennung[14].code = 'E';
  strcpy(kennung[14].land, "Slowakei");
  
  kennung[15].rest = 4;
  kennung[15].code = 'D';
  strcpy(kennung[15].land, "Estland");

  return kennung;
}

//###############################################################################
/** 
  Ermittelt das Vorhandensein des übergebenen Symbol in einer definierten Struktur
  und liefert das Ergebnis mit 1 oder 0
  
  @param  symbol  Das zu überprüfendes Symbol

  @return Liefert Wahr (1) oder Falsch (0) als Ergebnis der Prüfung
**/
//###############################################################################
int validiere_euro_symbol(char symbol)
{
  int ergebnis = 0;
  struct nzb *kennung = daten();

  for (int i = 0; 0 < strlen(kennung[i].land); i++)
  {
    if (kennung[i].code == symbol)
      ergebnis = 1;
  }

  free(kennung);
  return ergebnis;
}

//###############################################################################
/**
  Ermittelt das Vorhandensein des übergebenen Symbol in einer definierten Struktur
  und liefert bei Erfolg den dazu gehörigen 'Neunerrest'
  
  @param  symbol  Das zu überprüfendes Symbol

  @return Liefert den 'Neunerrest' oder -1
**/
//###############################################################################
int ermittle_euro_rest(char symbol)
{
  int ergebnis = -1;
  struct nzb *kennung = daten();

  for (int i = 0; 0 < strlen(kennung[i].land); i++)
  {
    if (kennung[i].code == symbol)
      ergebnis = kennung[i].rest;
  }

  free(kennung);
  return ergebnis;
}

//###############################################################################
/** 
  Ermittelt das Vorhandensein des übergebenen Symbol in einer definierten Struktur
  und liefert bei Erfolg die dazu gehörige Bezeichnung
  
  @param  symbol  Das zu überprüfendes Symbol

  @return Liefert die Bezeichnung oder leere Zeichenkette
**/
//###############################################################################
char *ermittle_euro_land(char symbol)
{
  char *ergebnis = (char *) calloc(20, sizeof(char));
  struct nzb *kennung = daten();

  for (int i = 0; 0 < strlen(kennung[i].land); i++)
  {
    if (kennung[i].code == symbol)
      strcpy(ergebnis, kennung[i].land);
  }

  free(kennung);
  return ergebnis;
}

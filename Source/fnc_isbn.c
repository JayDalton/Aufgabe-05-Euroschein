//###############################################################################
/**
  Berechnet die ISBN-Prüfziffer anhand der übergebenen Zeichenkette und liefert
  der Wert als Ganzzahl.
  
  @param  symbole Seriennummer als Zeichenkette

  @return Liefert Prüfziffer als Ganzzahl
**/
//###############################################################################
int berechne_isbn_pruefziffer(char *symbole)
{
  int summe = 0, symbol = 0;
  
  for (unsigned int i = 0; i < strlen(symbole); i++)
  {
    symbol = (47 < symbole[i] && symbole[i] < 58) ? symbole[i] - 48 : 0;
    summe += (i % 2) ? (3 * symbol) : symbol;
  }

  return (10 - (summe % 10)) % 10;
}

//###############################################################################
/** 
  Formatiert die übergebene Zeichenkette in die für ISBN-13 übliche Form.
  Ein Beispiel der Formatierung: 978-3-86680-192-9
  
  @param  symbole Zeiger auf die zu formatierende Zeichenkette 

  @return Liefert Zeiger auf die erstellte Zeichenkette
**/
//###############################################################################
char *erstelle_isbn_format(char *symbole)
{
  char *ergebnis = (char *) calloc(20, sizeof(char));
  char *prefix = extrahiere_bereich(symbole, 0, 3);
  char *gruppe = extrahiere_bereich(symbole, 3, 1);
  char *verlag = extrahiere_bereich(symbole, 4, 5);
  char *nummer = extrahiere_bereich(symbole, 9, 3);
  char *ziffer = extrahiere_bereich(symbole, 12, 1);
  
  sprintf(ergebnis, "%s-%s-%s-%s-%s", 
    prefix, gruppe, verlag, nummer, ziffer
  );
  
  free(prefix);
  free(gruppe);
  free(verlag);
  free(nummer);
  free(ziffer);
  
  return ergebnis;
}

//###############################################################################
/** 
  Validiert übergebene Zeichenkette auf die Repräsentation einer gültigen ISBN-13
  Enthaltene Fehler werden als Bitmuster erfasst und zurückgegeben.
  
  @param  nummer  die zu überprüfende Zeichenkettte
  @param  maximum die zu überprüfende Länge

  @return Liefert enthaltene Fehler als Bitmuster
**/
//###############################################################################
unsigned int validiere_isbn_nummer(char *nummer, unsigned int maximum)
{
  unsigned int ergebnis = 0;
  unsigned int laenge = strlen(nummer);
  
  ergebnis |= (laenge == 0) ? 1 : 0;
  ergebnis |= (laenge < maximum) ? 2 : 0;
  ergebnis |= (laenge > maximum) ? 4 : 0;
  
  for (unsigned int i = 0; i < laenge && i < maximum; i++)
  {
    ergebnis |= isalpha(nummer[i]) ? 8 : 0;
    ergebnis |= isdigit(nummer[i]) ? 0 : 16;
    ergebnis |= islower(nummer[i]) ? 32 : 0;
  }
  
  return ergebnis;
}

//###############################################################################
/** 
  Schreibt für das übergebene Bitmuster die Fehlernachrichten in die Standard-
  ausgabe. 
  
  @param  fehler  Bitmuster als Ausdruck enthaltener Fehler
**/
//###############################################################################
void schreibe_isbn_fehler(unsigned int fehler)
{
  char *ausgabe[] = {
    "Die Seriennummer ist zu leer.",
    "Die Seriennummer ist zu kurz.",
    "Die Seriennummer ist zu lang.",
    "Erstes Symbol ist kein Buchstabe.",
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

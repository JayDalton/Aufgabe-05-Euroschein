//###############################################################################
/** 
  Leert den Puffer der Standard-Eingabe.
**/
//###############################################################################
void reinige_eingabe(void)
{
  while (getchar() != 10);
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer ganzen Zahl zwischen zwei gegebenen Grenzen auf.
  
  @param  titel Beschriftung der Eingabeaufforderung  
  @param  minimum Minimum des definierten Wertebereiches
  @param  maximum Maximum des definierten Wertebereiches

  @return Die im Wertebereich definierte Ganzzahl
**/
//###############################################################################
int erfasse_ganzzahl(const char *titel, int minimum, int maximum)
{
  int ergebnis = 0;

  printf("\n%s: ", titel);

  while (scanf("%d%*[^\n]", &ergebnis) == 0 || (ergebnis < minimum || maximum < ergebnis)) 
  {
    printf("\nBitte Werte von '%i' bis '%i' eingeben: ", minimum, maximum);
    reinige_eingabe();
  }

  reinige_eingabe();

  return ergebnis;
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Gleitkommazahl zwischen zwei gegebenen Grenzen auf.

  @param  titel Beschriftung der Eingabeaufforderung  
  @param  minimum Minimum des definierten Wertebereiches
  @param  maximum Maximum des definierten Wertebereiches

  @return Die im Wertebereich definierte Gleitkommazahl.
*/
//###############################################################################
double erfasse_gleitzahl(const char *titel, double minimum, double maximum)
{
  double ergebnis = 0;

  printf("\n%s: ", titel);

  while (scanf("%lf%*[^\n]", &ergebnis) == 0 || (ergebnis < minimum || maximum < ergebnis)) 
  {
    printf("\nBitte Werte von '%.2lf' bis '%.2lf' eingeben: ", minimum, maximum);
    reinige_eingabe();
  }

  reinige_eingabe();

  return ergebnis;
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Auswahl zwischen j/J und n/N auf.

  @param  titel Beschriftung der Eingabeaufforderung  

  @return Liefert 1 für Zustimmung und 0 für Ablehnung
*/
//###############################################################################
int erfasse_antwort(const char *titel)
{
  char *eingabe = (char *) calloc(10, sizeof(char));

  printf("\n%s: ", titel);

  while (scanf("%1s[jJnN]%*[^\n]", eingabe) == 0)
  {
    printf("\nBitte nur 'j' oder 'n' eingeben.\n");
    reinige_eingabe();
  }
  
  reinige_eingabe();

  return eingabe[0] == 'j' || eingabe[0] == 'J' ? 1 : 0;
}

//###############################################################################
/** 
  Die Funktion erzeugt die Ausgabe einer uebergebenen Zeichenkette und fordert 
  den Nutzer zur Eingabe einer Zeichenketten mit einer anzugebenen maximalen 
  Länge.

  @param  titel Beschriftung der Eingabeaufforderung  
  @param  maximum Maximale Länge der Eingabe

  @return Liefert Zeiger auf die erfasst Zeichenkette
*/
//###############################################################################
char *erfasse_zeichen(char *titel, unsigned int maximum)
{
  char format[20];
  char *eingabe = (char *) calloc(maximum + 1, sizeof(char));

  sprintf(format, "%%%d[^\n]", maximum); // "%10[^\n]"

  printf("\n\n%s : ", titel);

  scanf(format, eingabe);
  
  reinige_eingabe();
  
  return eingabe;
}


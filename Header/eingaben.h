/*###############################################################################
  Funktions-Prototypen 
###############################################################################*/
void reinige_eingabe(void);
int erfasse_antwort(const char *titel);
int erfasse_ganzzahl(const char *titel, int minimum, int maximum);
char *erfasse_zeichen(char *titel, unsigned int maximum);
double erfasse_gleitzahl(const char *titel, double minimum, double maximum);

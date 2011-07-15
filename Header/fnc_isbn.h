/*###############################################################################
  Funktions-Prototypen 
###############################################################################*/
unsigned int validiere_isbn_nummer(char *nummer, unsigned int maximum);
int berechne_isbn_pruefziffer(char *symbole);
void schreibe_isbn_fehler(unsigned int fehler);
char *erstelle_isbn_format(char *nummer);

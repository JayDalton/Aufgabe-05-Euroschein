/*###############################################################################
  Funktions-Prototypen 
###############################################################################*/
unsigned int validiere_euro_nummer(char *nummer, unsigned int maximum);
void schreibe_euro_fehler(unsigned int fehler);
int berechne_euro_quersumme(char *symbole);
int validiere_euro_symbol(char symbol);
char *ermittle_euro_land(char symbol);
int ermittle_euro_rest(char symbol);
struct nzb *daten(void);
struct nzb {
  int rest;
  char code;
  char land[20];
};


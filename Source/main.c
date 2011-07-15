/*###############################################################################
  Kodierung: UTF-8 ohne BOM
###############################################################################*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "eingaben.h"
#include "symbole.h"
#include "dialoge.h"
#include "fnc_euro.h"
#include "fnc_isbn.h"

#include "eingaben.c"
#include "symbole.c"
#include "dialoge.c"
#include "fnc_euro.c"
#include "fnc_isbn.c"

//###############################################################################
/**
  Das Programm dient der Berechnung der Prüfziffern und der Validierung von an zu
  gebenen Seriennummern bei Euroscheinen und ISBN.

  @author Thomas Gerlach
  @version 1.0 
**/
//###############################################################################
int main(void)
{
  system("clear");
  unsigned int auswahl = 0;
  
  do {
    printf("\n\n\tS e r i e n n u m m e r\n\n");
    auswahl = dialog_menue_auswahl();
    switch (auswahl)
    {
      case 1:
        dialog_euro_ermitteln();
        break;
      case 2:
        dialog_euro_pruefen();
        break;
      case 3:
        dialog_isbn_ermitteln();
        break;
      case 4:
        dialog_isbn_pruefen();
        break;
      default:
        printf("\n\nProgramm wird beendet!\n\n");
        break;
    }
  } while (auswahl < 5);
  
  printf("\n\n\tAuf Wiedersehen!\n\n");
}

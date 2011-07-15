//###############################################################################
/** 
  Steuert die Dialogfunktionen und fordert den Nutzer zur Auswahl auf. 
  Liegt die Nutzereingabe nicht im Wertebereich wird die Eingabe wiederholt.
  
  @return Liefert eine Identifikation des gewählten Untermenüs
**/
//###############################################################################
unsigned int dialog_menue_auswahl(void)
{
  char *auswahl[] = {
    "Pruefziffer fuer Euro-Scheine ermitteln", 
    "Seriennummer von Euro-Scheinen pruefen", 
    "Pruefziffer fuer die ISBN-13 ermitteln", 
    "Pruefziffer fuer die ISBN-13 pruefen", 
    "Programm beenden"
  };

  for (unsigned int i = 0; i < (sizeof(auswahl) / sizeof(auswahl[0])); i++)
  {
      printf("\n(%d)%-4s%s", i + 1, "", auswahl[i]);
  }
  
  return erfasse_ganzzahl("\nTreffen Sie eine Auswahl", 1, 5);
}

//###############################################################################
/**
  Steuert den Dialog zur Ermittlung der Euro-Prüfziffer. Notwendige Eingaben
  werden beschrieben, geprüft und ggf. zur Wiederholung aufgefordert. Bei 
  erfolgreicher Übernahme wird die Prüfziffer gebildet und ausgegeben.
**/
//###############################################################################
void dialog_euro_ermitteln(void)
{
  int fehler = 0;
  char *eingabe = NULL;
  char *ausgabe[] = {
    "Bitte die Seriennummer eingeben [Großbuchstabe gefolgt von Ziffern]",
    "Die Prüfziffer ist",
  };

  do {

    eingabe = erfasse_zeichen(ausgabe[0], 20);
    fehler = validiere_euro_nummer(eingabe, 11);  // ohne Prüfziffer
    schreibe_euro_fehler(fehler);

  } while (fehler);

  int summe = berechne_euro_quersumme(eingabe);
  printf("\n%s: %d", ausgabe[1], summe < 9 ? 9 - summe : 9);
  
  free(eingabe);
}

//###############################################################################
/** 
  Steuert den Dialog zur Prüfung der Euro-Seriennummer. Notwendige Eingaben
  werden beschrieben, geprüft und ggf. zur Wiederholung aufgefordert. Bei 
  erfolgreicher Übernahme wird die Seriennummer validiert und das Ergebnis 
  ausgegeben.
**/
//###############################################################################
void dialog_euro_pruefen(void)
{
  int fehler = 0;
  char *eingabe = NULL;
  char *ausgabe[] = {
    "Bitte die Seriennummer eingeben [Großbuchstabe gefolgt von Ziffern]",
    "Die Seriennummer",
    "ist korrekt.",
    "ist falsch.",
  };
    
  do {

    eingabe = erfasse_zeichen(ausgabe[0], 20);
    fehler = validiere_euro_nummer(eingabe, 12); // mit Prüfziffer
    schreibe_euro_fehler(fehler);

  } while (fehler);

  char *ziffern = extrahiere_bereich(eingabe, 1, 11);
  int summe = berechne_euro_quersumme(eingabe);
  int check = berechne_euro_quersumme(ziffern);
  int rest = ermittle_euro_rest(eingabe[0]);

  if (summe % 9 == 0 && check % 9 == rest)
  {
    printf("\n%s %s %s", ausgabe[1], eingabe, ausgabe[2]);
    printf("\nAusgabeland: %s", ermittle_euro_land(eingabe[0]));

  } else {

    printf("\n%s %s %s", ausgabe[1], eingabe, ausgabe[3]);
    printf("\nDie Prüfziffer ist falsch.");
  }

  free(ziffern);
  free(eingabe);
}

//###############################################################################
/** 
  Steuert den Dialog zur Ermittlung der ISBN-Prüfziffer. Notwendige Eingaben 
  werden beschrieben, geprüft und ggf. zur Wiederholung aufgefordert. Bei 
  erfolgreicher Übernahme wird die Prüfziffer gebildet und ausgegeben.
**/
//###############################################################################
void dialog_isbn_ermitteln(void)
{
  int fehler = 0;
  char *nummer = NULL;
  char *eingabe = NULL;
  char *ausgabe[] = {
    "Bitte die Seriennummer eingeben",
    "Die Prüfziffer ist",
  };

  do {
    
    eingabe = erfasse_zeichen(ausgabe[0], 20);
    nummer = extrahiere_ziffern(eingabe);
    fehler = validiere_isbn_nummer(nummer, 12);
    schreibe_isbn_fehler(fehler);

  } while (fehler);

  printf("\n%s %i", ausgabe[1], berechne_isbn_pruefziffer(nummer));
  
  free(nummer);
  free(eingabe);
}

//###############################################################################
/** 
  Steuert den Dialog zur Prüfung der ISBN-Seriennummer. Notwendige Eingaben
  werden beschrieben, geprüft und ggf. zur Wiederholung aufgefordert. Bei 
  erfolgreicher Übernahme wird die Seriennummer validiert und das Ergebnis 
  ausgegeben.
**/
//###############################################################################
void dialog_isbn_pruefen(void)
{
  int fehler = 0;
  char *nummer = NULL;
  char *eingabe = NULL;
  char *ausgabe[] = {
    "Bitte die Seriennummer eingeben",
    "Die Seriennummer",
    "ist korrekt.",
    "ist falsch.",
  };

  do {
    
    eingabe = erfasse_zeichen(ausgabe[0], 20);
    nummer = extrahiere_ziffern(eingabe);
    fehler = validiere_isbn_nummer(nummer, 13);
    schreibe_isbn_fehler(fehler);

  } while (fehler);

  // Summierung mit Prüfziffer bei fehlerfreier ISBN immer 0.
  printf("\n%s %s %s", ausgabe[1], erstelle_isbn_format(nummer),
    berechne_isbn_pruefziffer(nummer) == 0 ? ausgabe[2] : ausgabe[3]
  );
  
  free(nummer);
  free(eingabe);
}


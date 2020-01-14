#include "Afficheur.h"
#include <iostream>
#include "Ligne.h"
using namespace std;


int main()
{
    // Ajouter votre code ici
    Afficheur aff;
	aff.ouvrirPortSerie("/dev/ttyUSB0");
	Ligne l;
	setEffetAffichage
	l.setMessage("BONJOUR TOUS LE MONDE !");
	aff.envoyerLigne(l);
    return 0;
}

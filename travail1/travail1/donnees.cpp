#include "donnees.h"

//Donnees lesDonneesDuProgramme
//finir 5 b)

Donnees::Donnees()
{
	intialiserPaquet();
}


void Donnees::intialiserPaquet() 
{
	int indiceAtout = 0;
	int indiceValeur = 0;
	int compteurTableau = 0;
		
	for (indiceAtout = 0; indiceAtout <= 3; indiceAtout++)
	{
		

			for (indiceValeur = 1; indiceValeur < 14; indiceValeur++)
			{

				Carte NouvelleCarte;
				if (indiceAtout == 0)
				{
					NouvelleCarte.InitialiserCarte(indiceValeur, "Pique")
						;
				}

				if (indiceAtout == 1)
				{
					NouvelleCarte.InitialiserCarte(indiceValeur, "Trefle");
				}

				if (indiceAtout == 2)
				{
					NouvelleCarte.InitialiserCarte(indiceValeur, "Carreaux");
				}

				if (indiceAtout == 3)
				{
					NouvelleCarte.InitialiserCarte(indiceValeur, "Coeur");

				}

				PaquetDeCarte[compteurTableau] = NouvelleCarte;
				compteurTableau++;
			}
	}
}


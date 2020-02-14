#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;

class Donnees
{
	public:
		Donnees();
		Joueur joueur1;
		Joueur joueur2;
		Carte PaquetDeCarte[maxCartes];
		void intialiserPaquet();

};


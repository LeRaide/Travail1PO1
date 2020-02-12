#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;

class Donnees
{
	public:
		Joueur joueur1;
		Joueur joueur2;
		Carte PaquetDeCarte[maxCartes];
		void intialiserPaquet();

};


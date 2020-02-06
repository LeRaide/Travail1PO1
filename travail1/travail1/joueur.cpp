#include "joueur.h"
Joueur::Joueur()
{
	int i = 0;
	NbDefaite = 0;
	nom = "";
	NbVictoire = 0;
	for (i = 0; i < maxCartesAJouer; i++)
	{
		mainDuJoueur[i] = NULL; // class creer un type qui sutilise comme un int
	}
	 

}
void Joueur::Setnom(string aNom) // programmer le set du nom  metre le nnom en majuscule
{
	nom = aNom;
}
void Joueur::AjouterCarteAlaMain(Carte* aCarte)
{
	int indice = 0;
		while (mainDuJoueur[indice] != NULL)
	{
			indice++;

	}
		mainDuJoueur[indice] = aCarte;
}
int Joueur::GetNbVictoire() const
{
	return NbVictoire;
}

int Joueur::GetNbDefaite() const
{
	return NbDefaite;
}
string Joueur::GetNom() const
{
	return nom;
}
Carte* Joueur::GetCarte(int aIndice) 
{
	return mainDuJoueur[aIndice];
}
void Joueur::EnleverCarte()
{
	int i = 0;
	for (i = 0; i < maxCartesAJouer; i++)
	{
		mainDuJoueur[i] = NULL; // class creer un type qui sutilise comme un int
	}
}
void Joueur::AugmenterNbVictoire()
{
	NbVictoire++;
}

void Joueur::AugmenterNbDefaite()
{
	NbDefaite++;
}
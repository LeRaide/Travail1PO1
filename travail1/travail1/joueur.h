#include <string>
#include "carte.h"
using namespace std;

#ifndef JoueurH
#define JoueurH

const int maxCartesAJouer = 26;
class Joueur
{
private:

	int NbVictoire;  //chiffre
	string nom;  //pique, coeur, trèfle ou carreau
	int NbDefaite;
	Carte* mainDuJoueur[maxCartesAJouer]; // un tab de 26 element qui dedans a des Carte


public:
	Joueur(); // constructeur
	void Setnom(string aNom); 
	void AjouterCarteAlaMain(Carte* aCarte);
		int GetNbVictoire () const; // si il elle retourne quelque chose met sont type devant nom de fonction si elle ne modifie aucun attribu (rien) on met const
	int GetNbDefaite() const;
	string GetNom() const;
	Carte* GetCarte(int indice) ;
	void EnleverCarte();
	void AugmenterNbVictoire();
	void AugmenterNbDefaite();
};
#endif
#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;

void InitialiserJoueurs();
void Jouer();
int DemanderNbCarte();
void MelangerCarte();
void DistribuerLesCartes();


int main() 
{
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
}

void Jouer() 
{

	DemanderNbCarte();
	
}

void InitialiserJoueurs()
{
	string nomJoueur1;
	string nomJoueur2;

	cout << "Quelle est le nom du joueur 1 ?";
	cin >> nomJoueur1;
	leJeu.joueur1.Setnom(nomJoueur1);

	cout << "Quelle est le nom du joueur 2 ?";
	cin >> nomJoueur2;
	leJeu.joueur2.Setnom(nomJoueur2);
}
int DemanderNbCarte()
{
	int nombreCarteParJoueur;
	cout << "Combien de carte voulez-vous par usager?";
	cin >> nombreCarteParJoueur;
	return nombreCarteParJoueur;
}

void MelangerCarteTableau()
{
	int NombreAleatoire1 = 0;
	int NombreAleatoire2 = 0;

	srand(time(NULL));

	Carte tempo;
	
		for (int i = 0; i < 3000; i++)
		{
			

			NombreAleatoire1 = rand() % maxCartes;
			NombreAleatoire2 = rand() % maxCartes;
			tempo = leJeu.PaquetDeCarte[NombreAleatoire1];
			leJeu.PaquetDeCarte[NombreAleatoire1] = leJeu.PaquetDeCarte[NombreAleatoire2];
			leJeu.PaquetDeCarte[NombreAleatoire2] = tempo;
		}
}

void DistribuerLesCartes(int nombreCarteParJoueur)
{
	int indice = 0;
	for (indice = 0; indice < nombreCarteParJoueur; indice++)
	{
		if (indice % 2 == 0)
		{
			leJeu.joueur1.AjouterCarteAlaMain(Carte *indice)
		}
		}

	leJeu.PaquetDeCarte
}
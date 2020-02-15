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
void MelangerCarteTableau();
void DistribuerLesCartes(int nombreCarteParJoueur);
int AfficherLesCartes(int nombreCarteParJoueur, Joueur LeJoueur);
void AugmenterVictoireEtDefaite(int aResultatJoueur1, int aResultatJoueur2);
void AfficherGrandGagnant();
int main() 
{
	string leGagnant = "" ;
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;		
	}
	
	
	AfficherGrandGagnant();
	
}

void Jouer() 
{
	int NbCarteParJoueur = 0;
	int TotalJoueur1;
	int TotalJoueur2;
	NbCarteParJoueur = DemanderNbCarte();
	
	MelangerCarteTableau();
	DistribuerLesCartes(NbCarteParJoueur);
	TotalJoueur1 =  AfficherLesCartes(NbCarteParJoueur, leJeu.joueur1);
	TotalJoueur2 = AfficherLesCartes(NbCarteParJoueur, leJeu.joueur2);
	if (TotalJoueur1 > TotalJoueur2)
	{
		cout << "Le joueur " << leJeu.joueur1.GetNom() << "gagne !";
		AugmenterVictoireEtDefaite(TotalJoueur1, TotalJoueur2);
	}
	else
	{
		cout << "Le joueur " << leJeu.joueur2.GetNom() << "gagne !";
		AugmenterVictoireEtDefaite(TotalJoueur1, TotalJoueur2);
	}
	

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
	while (!((std::cin >> nombreCarteParJoueur) && (nombreCarteParJoueur > 0) && (nombreCarteParJoueur < 27))) // while not equal bool
	{
		if (std::cin.fail())
		{
			std::cout << "Saisie incorrecte, recommencez : ";
			std::cin.clear();
			std::cin.ignore(1500, '\n');
		}
		else
		{
			std::cout << "Le chiffre n'est pas entre 1 et 26, recommencez : ";
		}
	}
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
	for (indice = 0; indice < nombreCarteParJoueur*2; indice++)
	{
		if (indice % 2 == 0)
		{
			leJeu.joueur1.AjouterCarteAlaMain(&leJeu.PaquetDeCarte[indice]); //pour afficher le tableau

		}
		else
		{
			leJeu.joueur2.AjouterCarteAlaMain(&leJeu.PaquetDeCarte[indice]);
		}
		}

	leJeu.PaquetDeCarte;



}

int AfficherLesCartes(int nombreCarteParJoueur, Joueur LeJoueur)
{
	int indice = 0;
	int additionnerLesCartes = 0;
	cout << "Nom du joueur : " << LeJoueur.GetNom();
	cout << "il possède ces cartes :";
	for (indice = 0; indice < nombreCarteParJoueur; indice++)
	{
		cout << LeJoueur.GetCarte(indice)->GetValeur() << " de " << LeJoueur.GetCarte(indice)->GetAtout();
		additionnerLesCartes += LeJoueur.GetCarte(indice)->GetValeur();
	}
	cout << "le total de ses cartes additionner est :" << additionnerLesCartes;
	return additionnerLesCartes;
}

void AfficherGrandGagnant()
{
	if (leJeu.joueur1.GetNbVictoire() > leJeu.joueur2.GetNbVictoire())
	{
		cout << "Le joueur " << leJeu.joueur1.GetNom() << " est le gagnant avec " << leJeu.joueur1.GetNbVictoire() << "victoires et " << leJeu.joueur1.GetNbDefaite() <<  " defaites";
		cout << "Le joueur " << leJeu.joueur2.GetNom() << " est le perdant avec " << leJeu.joueur2.GetNbVictoire() << "victoires et " << leJeu.joueur2.GetNbDefaite() << " defaites";
		
	


	}
	else
	{
		cout << "Le joueur " << leJeu.joueur2.GetNom() << " est le gagnant avec " << leJeu.joueur2.GetNbVictoire() << "victoires et " << leJeu.joueur2.GetNbDefaite() << " defaites";
		cout << "Le joueur " << leJeu.joueur1.GetNom() << " est le perdant avec " << leJeu.joueur1.GetNbVictoire() << "victoires et " << leJeu.joueur1.GetNbDefaite() << " defaites";
	
	
	}
}
void AugmenterVictoireEtDefaite(int aResultatJoueur1, int aResultatJoueur2)
{
	if (aResultatJoueur1 > aResultatJoueur2)
	{
		leJeu.joueur1.AugmenterNbVictoire();
		leJeu.joueur2.AugmenterNbDefaite();
		cout << "Bien joue " << leJeu.joueur1.GetNom() << " tu gagnes cette partie";
	}
	else if (aResultatJoueur1 == aResultatJoueur2)
	{
		cout << "Bien joue au deux joueurs, il y a egalite";
	}
	else
	{
		leJeu.joueur2.AugmenterNbVictoire();
		leJeu.joueur1.AugmenterNbDefaite();
		cout << "Bien joue " << leJeu.joueur1.GetNom() << " tu gagnes cette partie";
	}
}


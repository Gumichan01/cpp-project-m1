
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

#include "../framework/F_Plateau.hpp"
#include "Afficheur.hpp"
#include "JeuSerpentEchelle.hpp"
#include "Joueur.hpp"


using namespace std;

string JeuSerpentEchelle::nomIA = "IA_";

JeuSerpentEchelle::JeuSerpentEchelle()
    : F_Jeu()
{
    // Vide
}


JeuSerpentEchelle::~JeuSerpentEchelle()
{
    // Vide
}


void JeuSerpentEchelle::creerJoueur()
{
    string nom;

    cout << "Saisir nom : " << endl;
    cin >> nom;
    cin.ignore();

    size_t pos = nom.find(nomIA);

    if(pos == string::npos)
        joueurs.push_back(new Joueurhumain(nom,1));
    else
        joueurs.push_back(new JoueurIA(nom,1));
}


void JeuSerpentEchelle::partieGagne(F_Joueur& j)
{
    for(vector<F_Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
    {
        liste_affichage[i]->afficherGagnant(j);
    }
}


int JeuSerpentEchelle::nbJoueurs()
{
    int nbj;

    do
    {
        cout << "Nombre de joueurs(2 à 4 joueurs) : " << endl;
        cin >> nbj;

    }while(nbj < 1 || nbj > 4);

    return nbj;
}


void JeuSerpentEchelle::demarrer()
{
    int nbj = nbJoueurs();

    if(nbj == 1)
    {
        creerJoueur();
        joueurs.push_back(new JoueurIA("IA",1));
    }
    else
    {
        for(int i = 0; i < nbj; i++)
        {
            creerJoueur();
        }
    }

    F_Plateau::init(100);
    ajoutSystemeAffichage(new AfficheurSerpent());
}


void JeuSerpentEchelle::lancerPartie()
{
    int tour = 1;
    bool stop = false;

    while(!stop)
    {
        cout << "\n> Tour n° " << tour << endl << endl;

        for(vector<F_Joueur *>::size_type i = 0; i < joueurs.size(); i++)
        {
            joueurs[i]->jouer();

            // Affichage position du joueur
            for(vector<F_Afficheur *>::size_type j = 0; j < liste_affichage.size(); j++)
            {
                liste_affichage[j]->afficherPositionJoueur(*(joueurs[i]));
            }

            if(joueurs[i]->gagne())
            {
                stop = true;
                partieGagne(*(joueurs[i]));
                break;
            }
        }

        if(!stop)
        {
            cout << " ==== Etat plateau ====" << endl;
            // Etat du jeu
            for(vector<F_Afficheur *>::size_type j = 0; j < liste_affichage.size(); j++)
            {
                liste_affichage[j]->afficherJeu();
            }
            cout << " ======================" << endl;
        }
        tour++;
    }
}

void JeuSerpentEchelle::arret()
{
    F_Plateau::detruire();
}


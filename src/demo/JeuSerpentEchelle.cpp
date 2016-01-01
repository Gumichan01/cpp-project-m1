
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

#include "../framework/F_Plateau.hpp"
#include "Afficheur.hpp"
#include "JeuSerpentEchelle.hpp"
#include "Joueur.hpp"


using namespace std;

JeuSerpentEchelle::JeuSerpentEchelle()
    : F_Jeu()
{
    // Vide
}


JeuSerpentEchelle::~JeuSerpentEchelle()
{
    // Vide
}


void JeuSerpentEchelle::demarrer()
{
    int nbj;
    /// @todo Ajout joueurs
    do
    {
        cout << "Nombre de joueurs(2 à 4 joueurs) : " << endl;
        cin >> nbj;

    }while(nbj < 1 || nbj > 4);


    if(nbj == 1)
    {
        string nom;
        cout << "Saisir nom : " << endl;
        cin >> nom;

        joueurs.push_back(new Joueurhumain(nom,1));
        joueurs.push_back(new JoueurIA("IA",1));
    }
    else
    {
        for(int i = 0; i < nbj; i++)
        {
            string nom_joueur;
            cout << "Saisir nom : " << endl;
            cin >> nom_joueur;

            joueurs.push_back(new Joueurhumain(nom_joueur,1));
        }
    }

    /// @todo Creation Plateau
    F_Plateau::init(100);

    /// @todo Ajout afficheur
    ajoutSystemeAffichage(new AfficheurSerpent());
}

void JeuSerpentEchelle::lancerPartie()
{
    int tour = 1;
    bool stop = false;

    while(!stop)
    {
        cout << "\nTour n° " << tour << endl;

        for(vector<F_Joueur *>::size_type i = 0; i < joueurs.size(); i++)
        {
            joueurs[i]->jouer();

            cout << "F_Joueur " << joueurs[i]->getNom() << " à la case numéro "
                 << joueurs[i]->getPosition() << endl;

            if(joueurs[i]->gagne())
            {
                stop = true;
                break;
            }
        }

        // Affichage F_Jeu
        for(vector<F_Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
        {
            liste_affichage[i]->afficherJeu();
        }
        tour++;
    }

}

void JeuSerpentEchelle::arret()
{
    F_Plateau::detruire();
}


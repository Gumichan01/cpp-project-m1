
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

#include "../framework/F_Afficheur.hpp"
#include "JeuSerpentEchelle.hpp"
#include "JoueurHumain.hpp"

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

        new Joueurhumain(nom,1);
        //joueurs.add(new Joueurhumain(nom,1));
        //joueurs.add(new JoueurIA());
    }
    else
    {
        /*for(int i = 0; i < nbj; i++)
        {
            string nom;
            cout << "Saisir nom : " << endl;
            cin >> nom;
        }*/
    }

    /// @todo Ajout afficheur
}

void JeuSerpentEchelle::lancerPartie()
{
    bool stop = false;

    while(!stop)
    {
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
            liste_affichage[i]->afficherF_Jeu();
        }
    }

}

void JeuSerpentEchelle::arret()
{
    /// @todo
}


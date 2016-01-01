
#include <iostream>

#include "Afficheur.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Case.hpp"
#include "../framework/F_Joueur.hpp"

using namespace std;


AfficheurSerpent::AfficheurSerpent()
{
    // Vide
}


void AfficheurSerpent::afficherMenu()
{
    // Vide
}


void AfficheurSerpent::afficherJeu()
{
    F_Plateau *plateau = F_Plateau::getInstance();

    for(unsigned int i = 0; i < plateau->taille(); i++)
    {
        F_Case& c = plateau->operator[](i);

        if(!c.estVide())
            cout << " Case n° " << i  << " occupée" << endl;
    }
}


void AfficheurSerpent::afficherPositionJoueur(F_Joueur& j)
{
    cout << " " << j.getNom() << " est à la case numéro " << j.getPosition()
         << endl << endl;
}


AfficheurSerpent::~AfficheurSerpent()
{
    // Vide
}


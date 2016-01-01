
#include <iostream>

#include "Afficheur.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Case.hpp"

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

    cout << " ==== Etat plateau ====" << endl;

    for(unsigned int i = 0; i < plateau->taille(); i++)
    {
        F_Case& c = plateau->operator[](i);

        if(c.estVide())
            continue;
        else
        {
            cout << " Case n° " << i  << " occupée" << endl;
        }
    }
    cout << " ======================" << endl;
}


AfficheurSerpent::~AfficheurSerpent()
{
    // Vide
}


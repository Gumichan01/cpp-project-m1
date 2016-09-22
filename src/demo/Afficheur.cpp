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

// Indiques les cases non vides du plateau
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


// Indique où est le joueur sue le plateau
void AfficheurSerpent::afficherPositionJoueur(F_Joueur& j)
{
    cout << " | " << j.getNom() << " est à la case numéro "
         << j.getPosition() << ""
         << endl << endl;
}


void AfficheurSerpent::afficherGagnant(F_Joueur& j)
{
    cout << j.getNom() << " gagne le jeu." << endl;
}


AfficheurSerpent::~AfficheurSerpent()
{
    // Vide
}


AfficheurMultiPions::AfficheurMultiPions()
{
    // Vide
}

// Affiche les différent pions du joueur concerné
void AfficheurMultiPions::afficherPositionJoueur(F_Joueur& j)
{
    cout << " | " << j.getNom() << " a des pions au positions suivantes " << endl;
    cout << " -> ";

for(F_Pion p : j.getPions())
    {
        cout << p.getPosition() << " ";
    }
    cout << endl << endl;
}


AfficheurMultiPions::~AfficheurMultiPions()
{
    // Vide
}


















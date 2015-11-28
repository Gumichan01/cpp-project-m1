
#include "Jeu.hpp"
#include "Afficheur.hpp"

using namespace std;


Jeu::Jeu() {}


bool Jeu::ajoutSystemeAffichage(Afficheur *a)
{
    if(a == nullptr)
        return false;

    liste_affichage.push_back(a);
    return true;
}

bool Jeu::ajoutJoueur(Joueur *j)
{
    if(j == nullptr)
        return false;

    joueurs.push_back(j);
    return true;
}


Jeu::~Jeu()
{
    for(vector<Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
    {
        delete liste_affichage[i];
    }

    for(vector<Joueur *>::size_type i = 0; i < joueurs.size(); i++)
    {
        delete liste_affichage[i];
    }
}

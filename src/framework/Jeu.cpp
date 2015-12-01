
#include "Jeu.hpp"
#include "Joueur.hpp"
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


Joueur * Jeu::supprJoueur(unsigned int indice)
{
    if(indice > joueurs.size())
        return nullptr;

    Joueur *j = joueurs[indice];
    joueurs.erase(joueurs.begin() + indice);
    return j;
}


Afficheur * Jeu::supprSystemeAffichage(unsigned int indice)
{
    if(indice > liste_affichage.size())
        return nullptr;

    Afficheur * aff = liste_affichage[indice];
    liste_affichage.erase(liste_affichage.begin() + indice);
    return aff;
}


Jeu::~Jeu()
{
    for(vector<Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
    {
        delete liste_affichage[i];
    }

    for(vector<Joueur *>::size_type i = 0; i < joueurs.size(); i++)
    {
        delete joueurs[i];
    }

    liste_affichage.clear();
    joueurs.clear();
}

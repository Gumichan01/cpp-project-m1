
#include "F_Jeu.hpp"
#include "F_Joueur.hpp"
#include "F_Afficheur.hpp"

using namespace std;


Jeu::Jeu() {}

/**
*   @fn bool Jeu::ajoutSystemeAffichage(Afficheur *a)
*
*   Ajoute un système d'affichage
*
*   @param a Le pointeur vers un afficheur
*
*   @return Renvoie true Si le pointeur est valide, faux sinon
*
*/
bool Jeu::ajoutSystemeAffichage(Afficheur *a)
{
    if(a == nullptr)
        return false;

    liste_affichage.push_back(a);
    return true;
}

/**
*   @fn bool Jeu::ajoutJoueur(Joueur *j)
*
*   Ajoute un Joueur
*
*   @param j Le pointeur vers un Joueur
*
*   @return true Si le pointeur est valide, faux sinon
*
*/
bool Jeu::ajoutJoueur(Joueur *j)
{
    if(j == nullptr)
        return false;

    joueurs.push_back(j);
    return true;
}

/**
*   @fn Joueur * Jeu::supprJoueur(unsigned int indice)
*
*   Supprime un Joueur
*
*   @param indice L'indice vers un joueur
*
*   @return Un pointeur vers un joueur (peut être null)
*
*/
Joueur * Jeu::supprJoueur(unsigned int indice)
{
    if(indice > joueurs.size())
        return nullptr;

    Joueur *j = joueurs[indice];
    joueurs.erase(joueurs.begin() + indice);
    return j;
}

/**
*   @fn Afficheur * Jeu::supprSystemeAffichage(unsigned int indice)
*
*   Supprime un afficheur
*
*   @param indice L'indice vers un afficheur
*
*   @return Un pointeur vers un afficheur (peut être null)
*
*/
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


#include "F_Jeu.hpp"
#include "F_Joueur.hpp"
#include "F_Afficheur.hpp"

using namespace std;


F_Jeu::F_Jeu() {}

/**
*   @fn bool F_Jeu::ajoutSystemeAffichage(F_Afficheur *a)
*
*   Ajoute un système d'affichage
*
*   @param a Le pointeur vers un F_Afficheur
*
*   @return Renvoie true Si le pointeur est valide, faux sinon
*
*/
bool F_Jeu::ajoutSystemeAffichage(F_Afficheur *a)
{
    if(a == nullptr)
        return false;

    liste_affichage.push_back(a);
    return true;
}

/**
*   @fn bool F_Jeu::ajoutF_Joueur(F_Joueur *j)
*
*   Ajoute un F_Joueur
*
*   @param j Le pointeur vers un F_Joueur
*
*   @return true Si le pointeur est valide, faux sinon
*
*/
bool F_Jeu::ajoutF_Joueur(F_Joueur *j)
{
    if(j == nullptr)
        return false;

    joueurs.push_back(j);
    return true;
}

/**
*   @fn F_Joueur * F_Jeu::supprF_Joueur(unsigned int indice)
*
*   Supprime un F_Joueur
*
*   @param indice L'indice vers un joueur
*
*   @return Un pointeur vers un joueur (peut être null)
*
*/
F_Joueur * F_Jeu::supprF_Joueur(unsigned int indice)
{
    if(indice > joueurs.size())
        return nullptr;

    F_Joueur *j = joueurs[indice];
    joueurs.erase(joueurs.begin() + indice);
    return j;
}

/**
*   @fn F_Afficheur * F_Jeu::supprSystemeAffichage(unsigned int indice)
*
*   Supprime un F_Afficheur
*
*   @param indice L'indice vers un F_Afficheur
*
*   @return Un pointeur vers un F_Afficheur (peut être null)
*
*/
F_Afficheur * F_Jeu::supprSystemeAffichage(unsigned int indice)
{
    if(indice > liste_affichage.size())
        return nullptr;

    F_Afficheur * aff = liste_affichage[indice];
    liste_affichage.erase(liste_affichage.begin() + indice);
    return aff;
}


F_Jeu::~F_Jeu()
{
    for(vector<F_Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
    {
        delete liste_affichage[i];
    }

    for(vector<F_Joueur *>::size_type i = 0; i < joueurs.size(); i++)
    {
        delete joueurs[i];
    }

    liste_affichage.clear();
    joueurs.clear();
}



#include "F_Joueur.hpp"
#include "F_Pion.hpp"


int F_Joueur::id_compteur = 1;


F_Joueur::F_Joueur(std::string n, int nbPions)
    : id(id_compteur++), nom(n)
{
    for(int i = 0; i < nbPions; i++)
    {
        pions.push_back(F_Pion(id));
    }
}


F_Joueur::~F_Joueur()
{
    // Empty
}


// Obtenir son nom
std::string F_Joueur::getNom()
{
    return nom;
}


// Position du jeoueur quand il a un pion
int F_Joueur::getPosition()
{
    if(pions.size() == 1)
        return pions[0].getPosition();
    else
        return -1;
}


const std::vector<F_Pion>& F_Joueur::getPions()
{
    return pions;
}


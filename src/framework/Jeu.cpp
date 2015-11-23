
#include "Jeu.hpp"


Jeu::Jeu() {}


bool Jeu::ajoutSystemeAffichage(Afficheur *a)
{
    liste_affichage.push_back(a);
    return true;
}


Jeu::~Jeu()
{
    for(std::vector<Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
    {
        delete liste_affichage[i];
    }
}

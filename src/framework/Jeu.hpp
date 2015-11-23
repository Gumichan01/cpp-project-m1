
#ifndef JEU_H
#define JEU_H

#include <vector>

#include "Afficheur.hpp"

class Jeu
{
    std::vector<Afficheur*> liste_affichage;

public:

    Jeu();

    virtual void jouer() = 0;
    virtual void arret() = 0;

    bool ajoutSystemeAffichage(Afficheur *a);

    ~Jeu();
};


#endif

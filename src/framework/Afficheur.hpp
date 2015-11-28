
#ifndef AFFICHEUR_HPP
#define AFFICHEUR_HPP

#include <iostream>


class Afficheur
{

public:

    virtual void afficherMenu() = 0;
    virtual void afficherJeu() = 0;

    virtual ~Afficheur();
};

#endif

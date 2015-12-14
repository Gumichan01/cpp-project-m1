#ifndef JOUEURHUMAIN_HPP_INCLUDED
#define JOUEURHUMAIN_HPP_INCLUDED

#include "../framework/F_Joueur.hpp"
#include <iostream>

class Joueurhumain : public F_Joueur
{
public:
    Joueurhumain (std::string n,int nbPions, int sc = 0);
    void jouer();
    bool gagner();


private:
    bool passe_tour;

    virtual ~Joueurhumain();
};

#endif // JOUEURHUMAIN_HPP_INCLUDED
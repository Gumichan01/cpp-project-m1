#ifndef JOUEURHUMAIN_HPP_INCLUDED
#define JOUEURHUMAIN_HPP_INCLUDED

#include "../framework/F_Joueur.hpp"

class Joueurhumain : public F_Joueur
{
public:
    Joueurhumain(std::string n,int nbPions, int sc = 0);
    virtual void jouer();
    virtual bool gagne();

    virtual ~Joueurhumain();

private:
    bool passe_tour;
};


class JoueurIA : public Joueurhumain
{
public:
    JoueurIA(std::string n,int nbPions, int sc = 0);

    ~JoueurIA();
};

#endif // JOUEURHUMAIN_HPP_INCLUDED

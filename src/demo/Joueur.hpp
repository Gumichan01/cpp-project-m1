#ifndef JOUEURHUMAIN_HPP_INCLUDED
#define JOUEURHUMAIN_HPP_INCLUDED

#include "../framework/F_Joueur.hpp"



class JoueurIA : public F_Joueur
{
protected:
    bool passe_tour;

public:
    JoueurIA(std::string n,int nbPions, int sc = 0);

    virtual void jouer();
    virtual bool gagne();

    ~JoueurIA();
};


// Joueur humain
class Joueurhumain : public JoueurIA
{

public:
    Joueurhumain(std::string n,int nbPions, int sc = 0);
    virtual void jouer();

    virtual ~Joueurhumain();
};



class JoueurhumainPedago : public Joueurhumain
{

public:
    JoueurhumainPedago(std::string n,int nbPions, int sc = 0);
    virtual void jouer();

    virtual ~JoueurhumainPedago();
};



#endif // JOUEURHUMAIN_HPP_INCLUDED

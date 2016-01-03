#ifndef JOUEURHUMAIN_HPP_INCLUDED
#define JOUEURHUMAIN_HPP_INCLUDED

#include "../framework/F_Joueur.hpp"


/** Joueurs du jeu classique */

// Joueur IA du jeux classique
class JoueurIA : public F_Joueur
{
protected:
    bool passe_tour;
    void jouerPion(int num_pion = 0);

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


/** Joueur de la variante pédagogique */

// Joueur IA du jeu pédagogique
class JoueurIAPedago : public JoueurIA
{

public:
    JoueurIAPedago(std::string n,int nbPions, int sc = 0);
    virtual void jouer();

    virtual ~JoueurIAPedago();
};


// Joueur humain du jeu pédagogique
class JoueurhumainPedago : public Joueurhumain
{

public:
    JoueurhumainPedago(std::string n,int nbPions, int sc = 0);
    virtual void jouer();

    virtual ~JoueurhumainPedago();
};


/** Joueurs de la variante multi-pion */

// Joueur IA du jeu pédagogique
class JoueurIAMultiPions : public JoueurIA
{

public:
    JoueurIAMultiPions(std::string n,int nbPions, int sc = 0);
    //virtual void jouer();

    virtual ~JoueurIAMultiPions();
};


// Joueur humain du jeu multi pions
class JoueurhumainMultiPions : public Joueurhumain
{

public:
    JoueurhumainMultiPions(std::string n,int nbPions, int sc = 0);
    //virtual void jouer();

    virtual ~JoueurhumainMultiPions();
};


#endif // JOUEURHUMAIN_HPP_INCLUDED

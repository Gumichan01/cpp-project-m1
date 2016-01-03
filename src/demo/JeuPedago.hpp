#ifndef JEUPEDAGO_HPP_INCLUDED
#define JEUPEDAGO_HPP_INCLUDED

#include "JeuSerpentEchelle.hpp"


class JeuPedago : public JeuSerpentEchelle
{
protected:
    virtual void creerJoueur();

public:

    static bool quiz(F_Joueur& j,int rep = -1);

    JeuPedago();
    virtual void demarrer();
    ~JeuPedago();
};

#endif // JEUPEDAGO_HPP_INCLUDED

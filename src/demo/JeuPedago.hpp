#ifndef JEUPEDAGO_HPP_INCLUDED
#define JEUPEDAGO_HPP_INCLUDED

#include "JeuSerpentEchelle.hpp"


class JeuPedago : public JeuSerpentEchelle
{
protected:
    virtual void creerJoueur();

public:

    JeuPedago();
    virtual void demarrer();
    ~JeuPedago();
};

#endif // JEUPEDAGO_HPP_INCLUDED

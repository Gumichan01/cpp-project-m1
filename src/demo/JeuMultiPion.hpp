#ifndef JEUMULTIPION_HPP_INCLUDED
#define JEUMULTIPION_HPP_INCLUDED


#include "JeuSerpentEchelle.hpp"


// Classe décrivant le jeu avec plusieurs pions
class JeuMultiPion : public JeuSerpentEchelle
{
    static int nb_pions;
    static const int MAX_PIONS = 1024;
    int saisieNbPions();

protected:
    virtual void creerJoueur();

public:
    JeuMultiPion();

    virtual void demarrer();
    static const int getMaxPions();

    ~JeuMultiPion();
};

#endif // JEUMULTIPION_HPP_INCLUDED

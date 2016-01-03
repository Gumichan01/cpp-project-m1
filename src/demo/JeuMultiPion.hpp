#ifndef JEUMULTIPION_HPP_INCLUDED
#define JEUMULTIPION_HPP_INCLUDED


#include "JeuSerpentEchelle.hpp"


// Classe décrivant le jeu avec plusieurs pions
class JeuMultiPion : public JeuSerpentEchelle
{
    const int MAX_PIONS;
    static int nb_pions;
    int saisieNbPions();

protected:
    virtual void creerJoueur();

public:

    JeuMultiPion();
    virtual void demarrer();
    ~JeuMultiPion();
};

#endif // JEUMULTIPION_HPP_INCLUDED

#ifndef JEUMULTIPION_HPP_INCLUDED
#define JEUMULTIPION_HPP_INCLUDED


#include "JeuSerpentEchelle.hpp"


// Classe décrivant le jeu avec plusieurs pions
class JeuMultiPion : public JeuSerpentEchelle
{
    static int nb_pions;                // Nombre de pions à donner aux joueurs
    static const int MAX_PIONS = 16;    // Nombre maximale de pions par joueur
    int saisieNbPions();                // Saisie du nombre de pions

protected:
    virtual void creerJoueur();

public:
    JeuMultiPion();

    virtual void demarrer();
    static const int getMaxPions();

    ~JeuMultiPion();
};

#endif // JEUMULTIPION_HPP_INCLUDED

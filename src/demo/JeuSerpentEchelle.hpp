#ifndef JEU_SERPENT_ECHELLE_HPP
#define JEU_SERPENT_ECHELLE_HPP


#include "../framework/F_Jeu.hpp"

class F_Joueur;

class JeuSerpentEchelle : public F_Jeu
{

    void creerJoueur();
    void partieGagne(F_Joueur& j);

public:

    JeuSerpentEchelle();

    virtual void demarrer();
    virtual void lancerPartie();
    virtual void arret();

    virtual ~JeuSerpentEchelle();
};

#endif // JEU_SERPENT_ECHELLE_HPP


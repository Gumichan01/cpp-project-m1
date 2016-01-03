#ifndef JEU_SERPENT_ECHELLE_HPP
#define JEU_SERPENT_ECHELLE_HPP

#include <iostream>
#include "../framework/F_Jeu.hpp"

class F_Joueur;

class JeuSerpentEchelle : public F_Jeu
{

    void partieGagne(F_Joueur& j);

protected:

    static std::string nomIA;
    virtual void creerJoueur();
    int nbJoueurs();

public:

    JeuSerpentEchelle();

    virtual void demarrer();
    virtual void lancerPartie();
    virtual void arret();

    virtual ~JeuSerpentEchelle();
};

#endif // JEU_SERPENT_ECHELLE_HPP


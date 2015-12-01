
#ifndef JEU_HPP
#define JEU_HPP

#include <vector>

class Afficheur;
class Joueur;

class Jeu
{
protected:

    std::vector<Joueur *> joueurs;              /* Liste de joueurs */
    std::vector<Afficheur *> liste_affichage;   /* Liste d'afficheurs */

public:

    Jeu();

    /**
    *   @fn virtual void demarrer()
    *
    *   Initialise le jeu
    *
    */
    virtual void demarrer() = 0;

    /**
    *   @fn virtual void lancerPartie()
    *
    *   Lance une partie
    *
    */
    virtual void lancerPartie() = 0;

    /**
    *   @fn virtual void arret()
    *
    *   Arrête le jeu
    *
    */
    virtual void arret() = 0;

    bool ajoutJoueur(Joueur *j);
    bool ajoutSystemeAffichage(Afficheur *a);

    Joueur * supprJoueur(unsigned int indice);
    Afficheur * supprSystemeAffichage(unsigned int indice);

    virtual ~Jeu();
};

#endif

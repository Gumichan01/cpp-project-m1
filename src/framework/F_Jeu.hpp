#ifndef F_Jeu_HPP
#define F_Jeu_HPP

#include <vector>

class F_Afficheur;
class F_Joueur;

class F_Jeu
{
protected:

    std::vector<F_Joueur *> joueurs;              /* Liste de joueurs */
    std::vector<F_Afficheur *> liste_affichage;   /* Liste de F_Afficheurs */

public:

    F_Jeu();

    /**
    *   @fn virtual void demarrer()
    *
    *   Initialise le F_Jeu
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
    *   Arrête le F_Jeu
    *
    */
    virtual void arret() = 0;

    bool ajoutF_Joueur(F_Joueur *j);
    bool ajoutSystemeAffichage(F_Afficheur *a);

    F_Joueur * supprF_Joueur(unsigned int indice);
    F_Afficheur * supprSystemeAffichage(unsigned int indice);

    virtual ~F_Jeu();
};

#endif

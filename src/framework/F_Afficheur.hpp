#ifndef AFFICHEUR_HPP
#define AFFICHEUR_HPP

/**
*   @class Afficheur
*
*   Class abstraite qui gère l'affichage
*
*/
class Afficheur
{

public:

    /**
    *   @fn virtual void afficherMenu()
    *
    *   Afficher le menu principal
    *
    */
    virtual void afficherMenu() = 0;

    /**
    *   @fn virtual void afficherJeu()
    *
    *   Afficher l'état du jeu
    *
    */
    virtual void afficherJeu() = 0;

    virtual ~Afficheur();
};

#endif

#ifndef F_Afficheur_HPP
#define F_Afficheur_HPP

/**
*   @class F_Afficheur
*
*   Class abstraite qui gère l'affichage
*
*/
class F_Afficheur
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
    *   @fn virtual void afficherF_Jeu()
    *
    *   Afficher l'état du F_Jeu
    *
    */
    virtual void afficherF_Jeu() = 0;

    virtual ~F_Afficheur();
};

#endif

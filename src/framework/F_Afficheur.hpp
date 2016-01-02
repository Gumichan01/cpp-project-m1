#ifndef F_Afficheur_HPP
#define F_Afficheur_HPP

class F_Joueur;

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
    virtual void afficherJeu() = 0;

    /**
    *   @fn virtual void afficherPositionJoueur(F_Joueur& j)
    *
    *   Afficher La position du joueur
    *
    */
    virtual void afficherPositionJoueur(F_Joueur& j) = 0;

    /**
    *   @fn virtual void afficherGagnant(F_Joueur& j)
    *
    *   Afficher le nom du gagnant
    *
    */
    virtual void afficherGagnant(F_Joueur& j) = 0;

    virtual ~F_Afficheur();
};

#endif

#ifndef AFFICHEUR_HPP_INCLUDED
#define AFFICHEUR_HPP_INCLUDED

#include "../framework/F_Afficheur.hpp"

/*  Afficheur du jeu de serpent.
    Appliqué au jeu classique
    et au jeu pédagogique
*/
class AfficheurSerpent : virtual public F_Afficheur
{

public:

    AfficheurSerpent();

    virtual void afficherMenu();
    virtual void afficherJeu();
    virtual void afficherPositionJoueur(F_Joueur& j);
    virtual void afficherGagnant(F_Joueur& j);

    ~AfficheurSerpent();
};


/*  */
class AfficheurMultiPions : public  AfficheurSerpent
{

public:

    AfficheurMultiPions();

    virtual void afficherPositionJoueur(F_Joueur& j);

    ~AfficheurMultiPions();
};


#endif // AFFICHEUR_HPP_INCLUDED

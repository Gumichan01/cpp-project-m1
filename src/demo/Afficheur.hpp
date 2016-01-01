#ifndef AFFICHEUR_HPP_INCLUDED
#define AFFICHEUR_HPP_INCLUDED


#include "../framework/F_Afficheur.hpp"


class AfficheurSerpent : virtual public F_Afficheur
{

public:

    AfficheurSerpent();

    virtual void afficherMenu();
    virtual void afficherJeu();

    ~AfficheurSerpent();
};

#endif // AFFICHEUR_HPP_INCLUDED

#ifndef JOUEURIA_HPP
#define JOUEURIA_HPP

#include <vector>

#include "F_Joueur.hpp"

class F_StrategieIA;

class F_JoueurIA : public F_Joueur
{
protected:

    F_StrategieIA * strat;

public:

    F_JoueurIA();

    void jouer();
    bool gagne();
    bool ajoutStrategie(F_StrategieIA * st);

    virtual ~F_JoueurIA();
};

#endif // JOUEURIA_HPP

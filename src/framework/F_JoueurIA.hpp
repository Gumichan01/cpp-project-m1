
#ifndef JOUEURIA_HPP
#define JOUEURIA_HPP

#include <vector>

#include "F_Joueur.hpp"

class StrategieIA;

class JoueurIA : public Joueur
{
protected:

    StrategieIA * strat;

public:

    JoueurIA();

    void jouer();
    bool ajoutStrategie(StrategieIA * st);

    virtual ~JoueurIA();
};

#endif // JOUEURIA_HPP


#ifndef JOUEURIA_HPP
#define JOUEURIA_HPP

#include <vector>

#include "Joueur.hpp"

class StrategieIA;

class JoueurIA : public Joueur
{
    std::vector<StrategieIA *> strats;
    static int id;

public:

    JoueurIA();

    void lancerStrategies();
    virtual ~JoueurIA();
};

#endif // JOUEURIA_HPP


#ifndef JOUEURIA_HPP
#define JOUEURIA_HPP

#include <vector>

#include "Joueur.hpp"

class StrategieIA;

class JoueurIA : public Joueur
{
    /// @todo Refaire la structure interne
    std::vector<StrategieIA *> strats;
    static int id;

public:

    JoueurIA();

    void lancerStrategies();
    void lancerStrat(unsigned int index);
    bool ajoutStrategie(StrategieIA * st);

    virtual ~JoueurIA();
};

#endif // JOUEURIA_HPP

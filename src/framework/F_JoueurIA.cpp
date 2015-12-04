

#include "F_Strategie.hpp"
#include "F_JoueurIA.hpp"

using namespace std;


F_JoueurIA::F_JoueurIA() : F_Joueur("IA"), strat(nullptr)
{
    // Empty
}


void F_JoueurIA::jouer()
{
    strat->executer();
}


bool F_JoueurIA::ajoutStrategie(F_StrategieIA * st)
{
    if(st == nullptr)
        return false;

    delete strat;
    strat = st;

    return true;
}


F_JoueurIA::~F_JoueurIA()
{
    // Empty
}

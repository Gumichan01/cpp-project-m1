

#include "F_Strategie.hpp"
#include "F_JoueurIA.hpp"

using namespace std;


JoueurIA::JoueurIA() : Joueur("IA"), strat(nullptr)
{
    // Empty
}


void JoueurIA::jouer()
{
    strat->executer();
}


bool JoueurIA::ajoutStrategie(StrategieIA * st)
{
    if(st == nullptr)
        return false;

    delete strat;
    strat = st;

    return true;
}


JoueurIA::~JoueurIA()
{
    // Empty
}



#include "Strategie.hpp"
#include "JoueurIA.hpp"

using namespace std;

int JoueurIA::id = 1;

JoueurIA::JoueurIA() : Joueur("IA")
{
    // Empty
}

void JoueurIA::lancerStrategies()
{
    for(vector<StrategieIA *>::size_type i = 0; i != strats.size(); i++)
    {
        if(strats[i] != nullptr)
            strats[i]->executer();
    }
}


void JoueurIA::lancerStrat(unsigned int index)
{
    if(index < strats.size() && strats[index] != nullptr)
        strats[index]->executer();
}


bool JoueurIA::ajoutStrategie(StrategieIA * st)
{
    if(st == nullptr)
        return false;

    strats.push_back(st);
    return true;
}


JoueurIA::~JoueurIA()
{
    for(vector<StrategieIA *>::size_type i = 0; i < strats.size(); i++)
    {
        delete strats[i];
        strats[i] = nullptr;
    }
    strats.clear();
}

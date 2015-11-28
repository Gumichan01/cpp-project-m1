

#include "Strategie.hpp"
#include "JoueurIA.hpp"

using namespace std;

int JoueurIA::id = 1;

JoueurIA::JoueurIA() : Joueur("IA " + (id)++)
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


JoueurIA::~JoueurIA()
{
    for(vector<StrategieIA *>::size_type i = 0; i < strats.size(); i++)
    {
        delete strats[i];
        strats[i] = nullptr;
    }
    strats.clear();
}

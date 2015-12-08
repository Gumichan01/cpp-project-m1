

#include "F_Plateau.hpp"


static F_Plateau *singleton = nullptr;

F_Plateau::F_Plateau(int nbCases,bool isProcedural)
{
    if(isProcedural)
        generationProcedural();
    else
        generationClassique();
}

F_Plateau::~F_Plateau()
{
    for(std::vector<F_Case *>::size_type i = 0; i != cases.size(); i++)
    {
        delete enemies[i];
        enemies.erase(cases.begin() + i);
        i--;
    }
}

void F_Plateau::init(int nbCases, bool isProcedural)
{
    if(singleton == nullptr)
        singleton = new F_Plateau(nbCases,isProcedural);
}

F_Plateau * getInstance()
{
    return singleton;
}


void F_Plateau::detruire()
{
    delete singleton;
}


void F_Plateau::generationClassique()
{
    /// @todo Génération du plateau par défaut
}


void F_Plateau::generationProcedural()
{
    /// @todo Génération procédural du plateau
}


F_Case& F_Plateau::operator [](unsigned int index)
{
    return *(this->cases.at(index));
}











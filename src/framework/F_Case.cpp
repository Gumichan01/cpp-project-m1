
#include "F_Case.hpp"


F_Case::F_Case(TYPE_CASE ty, int ref_) : type(ty),ref_case(ref_),vide(false)
{
    // Empty
}

void F_Case::ajoutPion(F_Pion& p)
{
    pions[p.getID()] = &p;
}


void F_Case::enleverPion(int idPion)
{
    pions.erase(idPion);
}


TYPE_CASE F_Case::getType()
{
    return type;
}


bool F_Case::estVide()
{
    return vide;
}


F_Case::~F_Case()
{
    // Empty
}

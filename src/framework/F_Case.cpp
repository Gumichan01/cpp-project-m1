
#include "F_Case.hpp"


F_Case::F_Case(TYPE_CASE ty, int ref_) : type(ty),ref_case(ref_),vide(false)
{
    // Empty
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


#include "F_Case.hpp"


F_Case::F_Case(TYPE_CASE ty, int ref_) : type(ty),ref_case(ref_),vide(false)
{
    // Empty
}

// Ajoute un pion dans la liste des pions présents
void F_Case::ajoutPion(F_Pion& p)
{
    pions[p.getID()] = &p;

    if(vide == true)
        vide = false;
}

// Enlève un pion dans la liste des pions présents
void F_Case::enleverPion(int idPion)
{
    pions.erase(idPion);

    if(pions.empty())
        vide = true;
}

// Obtenir l'indice la case vers où faire le saut
int F_Case::getSautCase()
{
    return ref_case;
}

// Obtenir le type de la case
TYPE_CASE F_Case::getType()
{
    return type;
}

// Test si la case est vide
bool F_Case::estVide()
{
    return vide;
}


F_Case::~F_Case()
{
    // Empty
}


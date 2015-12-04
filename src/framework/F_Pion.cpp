

#include "F_Pion.hpp"

int F_Pion::id_compteur = 1;

F_Pion::F_Pion(int idJ) : id(id_compteur++),idJoueur(idJ), position(-1)
{
    // Empty
}

int F_Pion::getPosition()
{
    return position;
}


int F_Pion::getID()
{
    return idJoueur;
}

void F_Pion::setPosition(int id)
{
    if (id > 0)
        idJoueur = id;
}


F_Pion::~F_Pion()
{
    // Empty
}

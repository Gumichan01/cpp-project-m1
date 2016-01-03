
#include "F_Pion.hpp"

int F_Pion::id_compteur = 1;

F_Pion::F_Pion(int idJ) : id(id_compteur++),idJoueur(idJ), position(-1)
{
    // Empty
}


F_Pion::F_Pion(const F_Pion& p)
    : id(p.id),idJoueur(p.idJoueur), position(p.position)
{
    // Empty
}


F_Pion& F_Pion::operator=(F_Pion p)
{
    id = p.id;
    idJoueur = p.idJoueur;
    position = p.position;

    return *this;
}


int F_Pion::getPosition()
{
    return position;
}


int F_Pion::getID()
{
    return id;
}


int F_Pion::getIdJoueur()
{
    return idJoueur;
}


void F_Pion::setPosition(int pos)
{
    if (pos >= 0)
        position = pos;
}


F_Pion::~F_Pion()
{
    // Empty
}

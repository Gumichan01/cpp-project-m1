
#include "Joueur.hpp"


Joueur::Joueur(std::string n) : nom(n), score(0)
{
    // Empty
}


Joueur::Joueur(std::string n, int sc) : nom(n), score(sc)
{
    // Empty
}


Joueur::~Joueur()
{
    // Empty
}


std::string Joueur::getNom()
{
    return nom;
}


int Joueur::getScore()
{
    return score;
}

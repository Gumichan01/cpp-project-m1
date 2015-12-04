
#include "F_Joueur.hpp"


F_Joueur::F_Joueur(std::string n, int sc) : nom(n), score(sc)
{
    // Empty
}


F_Joueur::~F_Joueur()
{
    // Empty
}


std::string F_Joueur::getNom()
{
    return nom;
}


int F_Joueur::getScore()
{
    return score;
}


void F_Joueur::setScore(int newScore)
{
    if(newScore >= 0)
        score = newScore;
}

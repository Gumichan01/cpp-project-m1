
#include "F_Joueur.hpp"
#include "F_Pion.hpp"

int F_Joueur::id_compteur = 1;

F_Joueur::F_Joueur(std::string n, int nbPions, int sc)
    : id(id_compteur++), nom(n), score(sc)
{
    for(int i = 0; i < nbPions; i++)
    {
        pions.push_back(F_Pion(id));
    }
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

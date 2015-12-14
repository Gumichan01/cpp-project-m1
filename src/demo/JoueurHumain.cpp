#include "JoueurHumain.hpp"
#include "../framework/F_Pion.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Case.hpp"

#include <iostream>
#include<stdlib.h>
#include<time.h>


Joueurhumain::Joueurhumain(std::string n,int nbPions, int sc)
    : F_Joueur(n,nbPions,sc), passe_tour(false)

{
    // Vide
}

void Joueurhumain::jouer()
{

    if(passe_tour)
    {
        passe_tour = false;
    }
    else
    {
        int des= rand() %6 + 1;
        int position = pions[0].getPosition() + des;

        F_Plateau * plateau = F_Plateau::getInstance();
        F_Case& case_suivante = plateau->operator[](position);

        case_suivante.enleverPion(pions[0].getPosition());
/// @todo retour à la case départ si la case d'arrivée est occupée

        if()

        switch(case_suivante.getType())
        {
        case SAUT :
        {
            pions[0].setPosition(case_suivante.getSautCase());

            plateau->operator[](case_suivante.getSautCase()).ajoutPion(pions[0]);
        }
        break;

        case REJOUER:
        {
            pions[0].setPosition(position);
            case_suivante.ajoutPion(pions[0]);
            jouer();
        }
        break;

        case PASSE:
        {
            pions[0].setPosition(position);
            passe_tour=true;
        }
        break;

        default :
            pions[0].setPosition(position);
            break ;

        }
    }
}

bool Joueurhumain::gagner()
{

    for(F_Pion p : pions)
    {
        if(p.getPosition() != 100)
            return false;
    }
    return true;
}


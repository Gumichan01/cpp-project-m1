
#include "Joueur.hpp"
#include "../framework/F_Pion.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Case.hpp"

#include <iostream>

Joueurhumain::Joueurhumain(std::string n,int nbPions, int sc)
    : F_Joueur(n,nbPions,sc), passe_tour(false)

{
    // Vide
}


Joueurhumain::~Joueurhumain()
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
        // Lancer les dés
        int des = 6;//rand() %6 + 1;
        int position = pions[0].getPosition() + des;

        // Récuperer le plateau pour intéragir avec
        F_Plateau * plateau = F_Plateau::getInstance();

        // Le joueur quitte la case courant s'il y est
        if(pions[0].getPosition() > -1)
        {
            std::cout << "REMOVE" << std::endl;
            F_Case& case_courante = plateau->operator[](pions[0].getPosition());  // Avoir la case d'où le joueur part
            case_courante.enleverPion(pions[0].getIdJoueur());
        }

        F_Case& case_suivante = plateau->operator[](position);  // Avoir la case où le joueur va atterrir

        if(!case_suivante.estVide())
        {
            // Retour à la case départ
            pions[0].setPosition(0);
            plateau->operator[](0).ajoutPion(pions[0]);
        }
        else
        {
            // Selon le type de la case, effectuer une action donnée
            switch(case_suivante.getType())
            {
            case SAUT : // Echelle ou serpent
            {
                pions[0].setPosition(case_suivante.getSautCase());
                /*
                    Faire un saut vers la case pointée par
                    l'echelle ou le serpent
                */
                plateau->operator[](case_suivante.getSautCase()).ajoutPion(pions[0]);
            }
            break;

            case REJOUER :
            {
                pions[0].setPosition(position);
                case_suivante.ajoutPion(pions[0]);
                jouer();
            }
            break;

            case PASSE :
            {
                pions[0].setPosition(position);
                case_suivante.ajoutPion(pions[0]);
                passe_tour = true;
            }
            break;

            default :
                pions[0].setPosition(position);
                case_suivante.ajoutPion(pions[0]);
                break ;

            }
        }
    }
}


bool Joueurhumain::gagne()
{
    for(F_Pion p : pions)
    {
        if(p.getPosition() != 100)
            return false;
    }
    return true;
}


JoueurIA::JoueurIA(std::string n,int nbPions, int sc)
    : Joueurhumain(n,nbPions,sc)
{
    // Vide
}


JoueurIA::~JoueurIA()
{
    // Vide
}



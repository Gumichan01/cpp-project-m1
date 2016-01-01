
#include "Joueur.hpp"
#include "../framework/F_Pion.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Case.hpp"




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
        int des = rand() %6 + 1;
        int position = pions[0].getPosition() + des;

        // Récuperer le plateau pour intéragir avec
        F_Plateau * plateau = F_Plateau::getInstance();

        // Avoir la cas où le joueur va atterrir
        F_Case& case_suivante = plateau->operator[](position);

        // Le joueur quite la case courant
        case_suivante.enleverPion(pions[0].getPosition());


        if(!case_suivante.estVide())
        {
            plateau->operator[](0).ajoutPion(pions[0]);
            pions[0].setPosition(0);
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
                passe_tour = true;
            }
            break;

            default :
                pions[0].setPosition(position);
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


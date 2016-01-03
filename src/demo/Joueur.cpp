
#include "Joueur.hpp"
#include "../framework/F_Pion.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Case.hpp"

#include <iostream>

using namespace std;


Joueurhumain::Joueurhumain(std::string n,int nbPions, int sc)
    : JoueurIA(n,nbPions,sc)

{
    // Vide
}


Joueurhumain::~Joueurhumain()
{
    // Vide
}


void Joueurhumain::jouer()
{
    cout << nom << ", c'est à votre tour !" << endl
         << " Appuyez sur Entrée pour jouer !" << endl;
    cin.ignore();
    JoueurIA::jouer();
}


bool JoueurIA::gagne()
{
    F_Plateau *plateau = F_Plateau::getInstance();

    for(F_Pion p : pions)
    {
        if(p.getPosition() != static_cast<int>(plateau->taille()) -1)
            return false;
    }
    return true;
}


JoueurIA::JoueurIA(std::string n,int nbPions, int sc)
    : F_Joueur(n,nbPions,sc), passe_tour(false)
{
    // Vide
}

void JoueurIA::jouer()
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

        // Le joueur quitte la case courant s'il y est
        if(pions[0].getPosition() > -1)
        {
            F_Case& case_courante = plateau->operator[](pions[0].getPosition());  // Avoir la case d'où le joueur part
            case_courante.enleverPion(pions[0].getIdJoueur());
        }

        cout << " " << nom << " a lancé " << des << endl;

        if(static_cast<unsigned int>(position) >= plateau->taille())
        {
            position = (plateau->taille() - 1) - (position - (plateau->taille() - 1) );
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
                if(case_suivante.getSautCase() > position)
                    cout << " " << nom << " prend l'ECHELLE" << endl;
                else
                    cout << " " << nom << " se prend un serpent" << endl;

                pions[0].setPosition(case_suivante.getSautCase());
                plateau->operator[](case_suivante.getSautCase()).ajoutPion(pions[0]);
            }
            break;

            case REJOUER :
            {
                cout << " " << " Case SOLEIL : " << nom << " rejoue" << endl;
                pions[0].setPosition(position);
                case_suivante.ajoutPion(pions[0]);
                jouer();
            }
            break;

            case PASSE :
            {
                cout << " " << " Case PASSE : " << nom << " passe son tour" << endl;
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


JoueurIA::~JoueurIA()
{
    // Vide
}


JoueurIAPedago::JoueurIAPedago(std::string n,int nbPions, int sc)
    : JoueurIA(n,nbPions,sc)
{

}


void JoueurIAPedago::jouer()
{
    ///@todo Question
    JoueurIA::jouer();
}


JoueurIAPedago::~JoueurIAPedago()
{
    // Vide
}


JoueurhumainPedago::JoueurhumainPedago(std::string n,int nbPions, int sc)
    : Joueurhumain(n,nbPions,sc)
{

}



void JoueurhumainPedago::jouer()
{
    ///@todo Question
    Joueurhumain::jouer();
}


JoueurhumainPedago::~JoueurhumainPedago()
{
    // Vide
}



























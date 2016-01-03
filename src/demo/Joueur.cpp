
#include "Joueur.hpp"
#include "../framework/F_Pion.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Case.hpp"
#include "JeuPedago.hpp"

#include <iostream>

using namespace std;


/** Joueurs du jeu classique */

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
    cout << " " << nom << ", c'est à votre tour !" << endl
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

// Jouer un pion spécifique
void JoueurIA::jouerPion(int num_pion)
{
    if(passe_tour)
    {
        passe_tour = false;
    }
    else
    {
        // Lancer les dés
        int des = rand() %6 + 1;
        int position = pions[num_pion].getPosition() + des;

        // Récuperer le plateau pour intéragir avec
        F_Plateau * plateau = F_Plateau::getInstance();

        // Le joueur quitte la case courant s'il y est
        if(pions[num_pion].getPosition() > -1)
        {
            F_Case& case_courante = plateau->operator[](pions[num_pion].getPosition());  // Avoir la case d'où le joueur part
            case_courante.enleverPion(pions[num_pion].getIdJoueur());
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
            pions[num_pion].setPosition(0);
            plateau->operator[](0).ajoutPion(pions[num_pion]);
        }
        else
        {
            cout << " " << nom << " arrive à la case " << position << endl;
            // Selon le type de la case, effectuer une action donnée
            switch(case_suivante.getType())
            {
            case SAUT : // Echelle ou serpent
            {
                if(case_suivante.getSautCase() > position)
                    cout << " " << nom << " prend l'ECHELLE" << endl;
                else
                    cout << " " << nom << " se prend un serpent" << endl;

                pions[num_pion].setPosition(case_suivante.getSautCase());
                plateau->operator[](case_suivante.getSautCase()).ajoutPion(pions[0]);
            }
            break;

            case REJOUER :
            {
                cout << " " << " Case SOLEIL : " << nom << " rejoue" << endl;
                pions[num_pion].setPosition(position);
                case_suivante.ajoutPion(pions[0]);
                jouer();
            }
            break;

            case PASSE :
            {
                cout << " " << " Case PASSE : " << nom << " passe son tour" << endl;
                pions[num_pion].setPosition(position);
                case_suivante.ajoutPion(pions[0]);
                passe_tour = true;
            }
            break;

            default :
                pions[num_pion].setPosition(position);
                case_suivante.ajoutPion(pions[0]);
                break ;
            }
        }
    }
}


void JoueurIA::jouer()
{
    jouerPion();
}


JoueurIA::~JoueurIA()
{
    // Vide
}


JoueurIAPedago::JoueurIAPedago(std::string n,int nbPions, int sc)
    : JoueurIA(n,nbPions,sc)
{

}


/** Joueur de la variante pédagogique */


void JoueurIAPedago::jouer()
{
    if(JeuPedago::quiz(*this,rand()%100 +1))
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
    if(JeuPedago::quiz(*this))
        Joueurhumain::jouer();
}


JoueurhumainPedago::~JoueurhumainPedago()
{
    // Vide
}


/** Joueurs de la variante multi-pion */


JoueurIAMultiPions::JoueurIAMultiPions(std::string n,int nbPions, int sc)
    : JoueurIA(n,nbPions,sc)
{
    // Vide
}

/*void JoueurIAMultiPions::jouer()
{

}*/


JoueurIAMultiPions::~JoueurIAMultiPions()
{
    // Vide
}


// Joueur humain
JoueurhumainMultiPions::JoueurhumainMultiPions(std::string n,int nbPions, int sc)
    : Joueurhumain(n,nbPions,sc)
{
    // Vide
}


JoueurhumainMultiPions::~JoueurhumainMultiPions()
{
    // Vide
}


















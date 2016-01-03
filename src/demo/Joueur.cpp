#include "Joueur.hpp"
#include "../framework/F_Pion.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Case.hpp"
#include "JeuPedago.hpp"
#include "JeuMultiPion.hpp"

#include <iostream>

using namespace std;


/** Joueurs du jeu classique */

/// Joueur humain
Joueurhumain::Joueurhumain(std::string n,int nbPions)
    : JoueurIA(n,nbPions)

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


/// Joueur IA
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


JoueurIA::JoueurIA(std::string n,int nbPions)
    : F_Joueur(n,nbPions), passe_tour(false)
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

        cout << " " << nom << " arrive à la case " << position << endl;

        if(!case_suivante.estVide())
        {
            if(position != 100)
            {
                // Retour à la case départ
                cout << " Helas, cette case est déjà occupé. Retour à la case départ !" << endl;
                pions[num_pion].setPosition(0);
                plateau->operator[](0).ajoutPion(pions[num_pion]);
            }
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


/** Joueur de la variante pédagogique */

/// Joueur IA
JoueurIAPedago::JoueurIAPedago(std::string n,int nbPions)
    : JoueurIA(n,nbPions)
{

}

void JoueurIAPedago::jouer()
{
    if(JeuPedago::quiz(*this,rand()%100 +1))
        JoueurIA::jouer();
}


JoueurIAPedago::~JoueurIAPedago()
{
    // Vide
}


/// Joueur humain
JoueurhumainPedago::JoueurhumainPedago(std::string n,int nbPions)
    : Joueurhumain(n,nbPions)
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

/// Joueur IA
JoueurIAMultiPions::JoueurIAMultiPions(std::string n,int nbPions)
    : JoueurIA(n,nbPions)
{
    // Vide
}

void JoueurIAMultiPions::jouer()
{
    /**
        = Algo IA standard pour le multi-pions =

        On fait avancer en priorité les pions
        les plus éloignés de la case final

        NB :    Si tous les pions sont à la même position,
                l'indice des pions prévaut
    */
    const int sz = pions.size();
    int id_pion = 0;
    int min_pos = F_Plateau::getInstance()->taille() +1;

    /*
        On veut récupére l'indice du pion le plus éloigné
        Pour cela, on regarde la position du pion
    */
    for(int i = 0; i < sz; i++)
    {
        int pos = pions[i].getPosition();

        if(pos < min_pos)
        {
            id_pion = i;    // Indice
            min_pos = pos;  // Mise à jour de la position (la plus éloigée)
        }
    }

    cout << " " << nom << " utilise le pion à l'indice " << id_pion
         << " situé à la position " << pions[id_pion].getPosition() << endl;
    // Enfin, on joue avec le pion selectionné
    jouerPion(id_pion);
}


JoueurIAMultiPions::~JoueurIAMultiPions()
{
    // Vide
}


/// Joueur humain
JoueurhumainMultiPions::JoueurhumainMultiPions(std::string n,int nbPions)
    : Joueurhumain(n,nbPions)
{
    // Vide
}


void JoueurhumainMultiPions::jouer()
{
    const int sz = pions.size();
    int id_pion;

    cout << " Selectionnez l'indice du pion que vous voulez utiliser : " << endl;

    for(int i = 0; i < sz; i++)
    {
        cout << "  - Pion " << i << " à la position "
             << pions[i].getPosition() << endl;
    }

    do
    {
        cin >> id_pion;
    }
    while(id_pion < 0 || id_pion >= sz);

    // Selection faite, on peut jouer le pion
    jouerPion(id_pion);
}



JoueurhumainMultiPions::~JoueurhumainMultiPions()
{
    // Vide
}


#include "JeuMultiPion.hpp"
#include "Afficheur.hpp"
#include "../framework/F_Plateau.hpp"
#include "Joueur.hpp"

using namespace std;


int JeuMultiPion::nb_pions = 1;


JeuMultiPion::JeuMultiPion()
    : JeuSerpentEchelle()
{
    // Vide
}


JeuMultiPion::~JeuMultiPion()
{
    // Vide
}


// Saisir le nom du joueur
void JeuMultiPion::creerJoueur()
{
    string nom;

    cout << "Saisir nom joueur : " << endl;
    cin >> nom;
    cin.ignore();

    size_t pos = nom.find(nomIA);

    if(pos == string::npos)
        joueurs.push_back(new JoueurhumainMultiPions(nom,nb_pions));
    else
        joueurs.push_back(new JoueurIAMultiPions(nom,nb_pions));
}


// Saisir le nombre de pions
int JeuMultiPion::saisieNbPions()
{
    int nb;

    do
    {
        cout << "Saisir le nombre de pions par joueur : " << endl;
        cin >> nb;
    }
    while(nb < 0 && nb > MAX_PIONS);

    return nb;
}


void JeuMultiPion::demarrer()
{
    int nbj = nbJoueurs();
    nb_pions = saisieNbPions();

    if(nbj == 1)
    {
        creerJoueur();
        joueurs.push_back(new JoueurIAMultiPions("IA",nb_pions));
    }
    else
    {
        for(int i = 0; i < nbj; i++)
        {
            creerJoueur();
        }
    }

    F_Plateau::init(100);
    ajoutSystemeAffichage(new AfficheurMultiPions());
}


const int JeuMultiPion::getMaxPions()
{
    return MAX_PIONS;
}


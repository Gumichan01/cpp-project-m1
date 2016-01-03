

#include "JeuPedago.hpp"
#include "Afficheur.hpp"
#include "../framework/F_Plateau.hpp"
#include "Joueur.hpp"

using namespace std;

JeuPedago::JeuPedago()
    : JeuSerpentEchelle()
{
    // Vide
}


JeuPedago::~JeuPedago()
{
    // Vide
}


void JeuPedago::creerJoueur()
{
    string nom;

    cout << "Saisir nom : " << endl;
    cin >> nom;

    size_t pos = nom.find(nomIA);

    if(pos == string::npos)
        joueurs.push_back(new JoueurhumainPedago(nom,1));
    else
        joueurs.push_back(new JoueurIAPedago(nom,1));
}


void JeuPedago::demarrer()
{
    int nbj = nbJoueurs();

    if(nbj == 1)
    {
        creerJoueur();
        joueurs.push_back(new JoueurIAPedago("IA",1));
    }
    else
    {
        for(int i = 0; i < nbj; i++)
        {
            creerJoueur();
        }
    }

    F_Plateau::init(100);
    ajoutSystemeAffichage(new AfficheurSerpent());
}

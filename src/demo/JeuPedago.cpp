

#include "JeuPedago.hpp"
#include "Afficheur.hpp"
#include "../framework/F_Plateau.hpp"
#include "../framework/F_Joueur.hpp"
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


bool JeuPedago::quiz(F_Joueur& j,int rep)
{
    int x,y,z;
    int reponse;

    x = rand() %10 +1;
    y = rand() %10 +1;
    z = x*y;

    cout << "Combien font : " << x << "*" << y << " ?" << endl;

    if(rep == -1)
        cin >> reponse;
    else
        reponse = rep;

    cout << " " << j.getNom() << " propose " << reponse << endl;

    if(reponse == z)
    {
        cout << " Bonne réponse ! " << endl;
        return true;
    }
    else
    {
        cout << " Mauvaise réponse ! " << x << "*" << y << " = " << z << endl;
        return false;
    }
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

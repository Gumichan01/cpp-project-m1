

/*
    Ce fichier sert juste de test
*/


#include "../framework/Afficheur.hpp"
#include "../framework/Jeu.hpp"
#include "../framework/Joueur.hpp"
#include "../framework/JoueurIA.hpp"
#include "../framework/Strategie.hpp"

#include <iostream>

using namespace std;

class AffichageStd : virtual public Afficheur
{

public:

    AffichageStd(){}

    void afficherMenu()
    {
        cout << "Démarrage du programme test" << endl;
        cout << "Jeu en cours..." << endl;
    }

    void afficherJeu()
    {
        cout << "= Affichage du jeu OK =" << endl;
    }

    ~AffichageStd(){}
};


class JeuTest : public Jeu
{

public:

    JeuTest():Jeu(){}

    void demarrer()
    {
        //Affichage menu
        for(vector<Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
        {
            liste_affichage[i]->afficherMenu();
        }
    }

    void lancerPartie()
    {
        const int N = 10;
        int compteur = 0;

        while(compteur < N)
        {
            // Faire évoluer les joueurs
            // Affichage jeu
            for(vector<Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
            {
                liste_affichage[i]->afficherJeu();
            }

            compteur++;
        }
    }

    void arret()
    {
        cout << "... Fin du jeu" << endl;
    }

    ~JeuTest(){}
};


int main(void)
{
    JeuTest jeu;
    jeu.ajoutSystemeAffichage(new AffichageStd());

    // Algorithme de base pour lancer un jeu
    jeu.demarrer();
    jeu.lancerPartie();
    jeu.arret();

    return 0;
}

















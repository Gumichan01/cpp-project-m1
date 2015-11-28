

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
        cout << "Programme de test du framework" << endl;
    }

    void afficherJeu()
    {
        cout << "Jeu en cours..." << endl;
        cout << "= Etat du jeu =" << endl;
    }

    ~AffichageStd(){}
};



int main(void)
{
    Afficheur *afficheur = new AffichageStd();

    afficheur->afficherMenu();
    afficheur->afficherJeu();

    delete afficheur;
    return 0;
}

















/*
    Ce fichier sert juste de test
*/

#include "../framework/F_Afficheur.hpp"
#include "../framework/F_Jeu.hpp"
#include "../framework/F_Joueur.hpp"
#include "../framework/F_JoueurIA.hpp"
#include "../framework/F_Strategie.hpp"

#include <iostream>

using namespace std;

const int MAX_SCORE = 10;

// Classe de test pour l'affichage
class AffichageStd : virtual public F_Afficheur
{
    int etat;

public:

    AffichageStd() : etat(1) {}

    void afficherMenu()
    {
        cout << "Démarrage du programme test" << endl;
        cout << "F_Jeu en cours..." << endl;
    }

    void afficherF_Jeu()
    {
        cout << " = Affichage du F_Jeu OK = Etat " << (etat++) << endl << endl;
    }

    ~AffichageStd() {}
};

// Classe de test pour F_Jeu
class F_JeuTest : public F_Jeu
{

public:

    F_JeuTest():F_Jeu() {}

    void demarrer()
    {
        //Affichage menu
        for(vector<F_Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
        {
            liste_affichage[i]->afficherMenu();
        }
    }

    void lancerPartie()
    {
        bool stop = false;

        while(!stop)
        {
            // Faire évoluer les joueurs
            for(vector<F_Joueur *>::size_type i = 0; i < joueurs.size(); i++)
            {
                joueurs[i]->jouer();

                cout << "F_Joueur " << joueurs[i]->getNom() << " a désormais "
                     << joueurs[i]->getScore() << " points." << endl;

                if(joueurs[i]->gagne())
                {
                    stop = true;
                    break;
                }
            }

            // Affichage F_Jeu
            for(vector<F_Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
            {
                liste_affichage[i]->afficherF_Jeu();
            }
        }
    }

    void arret()
    {
        for(vector<F_Joueur *>::size_type i = 0; i < joueurs.size(); i++)
        {
            if(joueurs[i]->gagne())
            {
                cout << "Le gagnant est :'" << joueurs[i]->getNom()
                     << "' avec un score de " << joueurs[i]->getScore() << endl;
                cout << "... Fin du F_Jeu" << endl;
                break;
            }
        }
    }

    ~F_JeuTest() {}
};


class F_JoueurTest : public F_Joueur
{
public:

    F_JoueurTest(string nom) : F_Joueur(nom) {}

    void jouer()
    {
        score += rand()%4;
    }

    bool gagne()
    {
        return score > MAX_SCORE;
    }

    virtual ~F_JoueurTest() {}
};


class F_JoueurIATest : public F_JoueurIA
{
public:

    F_JoueurIATest() : F_JoueurIA() {}

    void jouer()
    {
        strat->executer();
    }

    bool gagne()
    {
        return score > MAX_SCORE*2;
    }

    virtual ~F_JoueurIATest() {}
};


class StrategieTest: public F_StrategieIA
{
public:

    StrategieTest(F_JoueurIATest* j): F_StrategieIA(j){}

    void executer()
    {
        ia->setScore(ia->getScore() + (rand()%7));
    }

    ~StrategieTest(){}
};


int main(void)
{
    F_JeuTest F_Jeu;

    F_JoueurIATest *ia = new F_JoueurIATest();
    ia->ajoutStrategie(new StrategieTest(ia));

    F_Jeu.ajoutF_Joueur(new F_JoueurTest("toto"));
    F_Jeu.ajoutF_Joueur(ia);
    F_Jeu.ajoutSystemeAffichage(new AffichageStd());
    srand(time(nullptr));

    // Algorithme de base pour lancer un F_Jeu
    F_Jeu.demarrer();
    F_Jeu.lancerPartie();
    F_Jeu.arret();

    return 0;
}


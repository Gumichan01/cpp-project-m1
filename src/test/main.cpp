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
class AffichageStd : virtual public Afficheur
{
    int etat;

public:

    AffichageStd() : etat(1) {}

    void afficherMenu()
    {
        cout << "Démarrage du programme test" << endl;
        cout << "Jeu en cours..." << endl;
    }

    void afficherJeu()
    {
        cout << " = Affichage du jeu OK = Etat " << (etat++) << endl << endl;
    }

    ~AffichageStd() {}
};

// Classe de test pour Jeu
class JeuTest : public Jeu
{

public:

    JeuTest():Jeu() {}

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
        bool stop = false;

        while(!stop)
        {
            // Faire évoluer les joueurs
            for(vector<Joueur *>::size_type i = 0; i < joueurs.size(); i++)
            {
                joueurs[i]->jouer();

                cout << "Joueur " << joueurs[i]->getNom() << " a désormais "
                     << joueurs[i]->getScore() << " points." << endl;

                if(joueurs[i]->gagne())
                {
                    stop = true;
                    break;
                }
            }

            // Affichage jeu
            for(vector<Afficheur *>::size_type i = 0; i < liste_affichage.size(); i++)
            {
                liste_affichage[i]->afficherJeu();
            }
        }
    }

    void arret()
    {
        for(vector<Joueur *>::size_type i = 0; i < joueurs.size(); i++)
        {
            if(joueurs[i]->gagne())
            {
                cout << "Le gagnant est :'" << joueurs[i]->getNom()
                     << "' avec un score de " << joueurs[i]->getScore() << endl;
                cout << "... Fin du jeu" << endl;
                break;
            }
        }
    }

    ~JeuTest() {}
};


class JoueurTest : public Joueur
{
public:

    JoueurTest(string nom) : Joueur(nom) {}

    void jouer()
    {
        score += rand()%4;
    }

    bool gagne()
    {
        return score > MAX_SCORE;
    }

    virtual ~JoueurTest() {}
};


class JoueurIATest : public JoueurIA
{
public:

    JoueurIATest() : JoueurIA() {}

    void jouer()
    {
        strat->executer();
    }

    bool gagne()
    {
        return score > MAX_SCORE*2;
    }

    virtual ~JoueurIATest() {}
};


class StrategieTest: public StrategieIA
{
public:

    StrategieTest(JoueurIATest* j): StrategieIA(j){}

    void executer()
    {
        ia->setScore(ia->getScore() + (rand()%7));
    }

    ~StrategieTest(){}
};


int main(void)
{
    JeuTest jeu;

    JoueurIATest *ia = new JoueurIATest();
    ia->ajoutStrategie(new StrategieTest(ia));

    jeu.ajoutJoueur(new JoueurTest("toto"));
    jeu.ajoutJoueur(ia);
    jeu.ajoutSystemeAffichage(new AffichageStd());
    srand(time(nullptr));

    // Algorithme de base pour lancer un jeu
    jeu.demarrer();
    jeu.lancerPartie();
    jeu.arret();

    return 0;
}


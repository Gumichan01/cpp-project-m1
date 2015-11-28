/*
    Ce fichier sert juste de test
*/

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../framework/Afficheur.hpp"
#include "../framework/Jeu.hpp"
#include "../framework/Joueur.hpp"
#include "../framework/JoueurIA.hpp"
#include "../framework/Strategie.hpp"

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
        score += rand()%7;
    }

    bool gagne()
    {
        return score > MAX_SCORE*2;
    }

    virtual ~JoueurIATest() {}
};


int main(void)
{
    JeuTest jeu;

    jeu.ajoutJoueur(new JoueurTest("toto"));
    jeu.ajoutJoueur(new JoueurIATest());
    jeu.ajoutSystemeAffichage(new AffichageStd());
    srand(time(nullptr));

    // Algorithme de base pour lancer un jeu
    jeu.demarrer();
    jeu.lancerPartie();
    jeu.arret();

    return 0;
}

















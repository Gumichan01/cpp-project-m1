
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>


class F_Joueur
{

static int id_compteur;

protected:

    int id;
    std::string nom;
    int score;

public:

    F_Joueur(std::string n, int sc = 0);

    virtual void jouer() = 0;   // le joueur joue
    virtual bool gagne() = 0;   // Vérifie si le joueur gagne

    std::string getNom();
    int getScore();

    void setScore(int newScore);

    virtual ~F_Joueur();
};

#endif

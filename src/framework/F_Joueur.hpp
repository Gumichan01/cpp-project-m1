
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include <string>

class F_Pion;

class F_Joueur
{

static int id_compteur;

protected:

    int id;
    std::string nom;
    int score;
    std::vector<F_Pion> pions;

public:

    F_Joueur(std::string n, int nbPions = 1, int sc = 0);

    virtual void jouer() = 0;   // le joueur joue
    virtual bool gagne() = 0;   // Vérifie si le joueur gagne

    std::string getNom();
    int getPosition();
    int getScore();
    const std::vector<F_Pion>& getPions();

    void setScore(int newScore);
    virtual ~F_Joueur();
};

#endif

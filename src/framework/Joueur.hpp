
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <string>


class Joueur
{

protected:

    std::string nom;
    int score;

public:

    Joueur(std::string n);
    Joueur(std::string n, int sc);

    virtual void jouer() = 0;   // le joueur joue
    virtual bool gagne() = 0;   // Vérifie si le joueur gagne

    std::string getNom();
    int getScore();

    void setScore(int newScore);

    ~Joueur();
};


#endif


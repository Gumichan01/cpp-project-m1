
#ifndef JEU_HPP
#define JEU_HPP

#include <vector>

class Afficheur;

class Jeu
{
    std::vector<Afficheur *> liste_affichage;

public:

    Jeu();

    virtual void lancerPartie() = 0;
    virtual void arret() = 0;

    bool ajoutSystemeAffichage(Afficheur *a);

    virtual ~Jeu();
};


#endif

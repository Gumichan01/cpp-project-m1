
#ifndef JEU_HPP
#define JEU_HPP

#include <vector>

class Afficheur;
class Joueur;

class Jeu
{
protected:

    std::vector<Joueur *> joueurs;
    std::vector<Afficheur *> liste_affichage;

public:

    Jeu();

    virtual void demarrer() = 0;
    virtual void lancerPartie() = 0;
    virtual void arret() = 0;

    /** @todo   Ajouter des méthodes de suppression et
                une méthode de mise à jour des affichages */
    bool ajoutJoueur(Joueur *j);
    bool ajoutSystemeAffichage(Afficheur *a);

    virtual ~Jeu();
};


#endif

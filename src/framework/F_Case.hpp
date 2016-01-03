#ifndef CASE_HPP
#define CASE_HPP

#include <map>
#include "F_Pion.hpp"


/**
    @enum TYPE_CASE

    Définit le type d'une case

    - NORMAL:   case normal sans effet
    - SAUT  :   case permettant de faire un saut vers une autre case
    - REJOUER : case permettant de rejouer sur un même tour
    - PASSE :   case qui fait passer un tour au joueur

    @note   Dans le jeu du serpent, le SAUT correspond à la fois
            à l'echelle et à la queue du serpent.

*/
typedef enum {NORMAL,SAUT,REJOUER,PASSE} TYPE_CASE;

/**
    @class F_Case

    Définit une case sur un plateau
*/
class F_Case
{
    TYPE_CASE type;
    int ref_case;      /* indice sur la case à sauter si elle existe, -1 sinon */
    bool vide;
    std::map<int,F_Pion*> pions;

public:

    F_Case(TYPE_CASE ty, int ref_ = -1);

    void ajoutPion(F_Pion& p);
    void enleverPion(int idPion);

    int getSautCase();
    int getJoueur();
    TYPE_CASE getType();
    bool estVide();

    ~F_Case();
};

#endif // CASE_HPP


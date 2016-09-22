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
    int ref_case;                   /**< Indice sur la case à sauter si elle existe, -1 sinon */
    bool vide;
    std::map<int,F_Pion*> pions;    /**< Liste de pions par clés*/

public:

    /**
    *   @fn F_Case(TYPE_CASE ty, int ref_ = -1)
    *
    *   Constructeur
    *
    *   @param ty Le type de case désiré
    *   @param ref_ L'indice de la case référencé par celui-çi
    */
    F_Case(TYPE_CASE ty, int ref_ = -1);

    /**
    *   @fn void ajoutPion(F_Pion& p);
    *
    *   Ajoute un pion
    *
    *   @param p Le pion à ajouter
    */
    void ajoutPion(F_Pion& p);

    /**
    *   @fn void enleverPion(F_Pion& p);
    *
    *   Enleve un pion
    *
    *   @param idPion Le pion à enlever
    */
    void enleverPion(int idPion);

    /**
    *   @fn int getSautCase()
    *
    *   Renvoie la case pointée par une case spéciale
    *
    *   @return L'indice de la case pointée, -1 sinon
    */
    int getSautCase();

    /**
    *   @fn int getJoueur()
    *
    *   Renvoie le joueur présent sur la case
    *
    *   @return L'ID du joueur présent,
    */
    int getJoueur();
    TYPE_CASE getType();    /**< Renvoie le type de la case */
    bool estVide();         /**< Indique si la case est vide ou non  */

    ~F_Case();
};

#endif // CASE_HPP

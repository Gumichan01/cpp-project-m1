#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include "F_Pion.hpp"

class F_Case;

/**
*   @class F_Plateau
*
*   Singleton plateau
*
*/
class F_Plateau
{
    std::vector<F_Case *> cases;

    F_Plateau(int nbCases, bool isProcedural=false);
    F_Plateau(F_Plateau& p);
    F_Plateau& operator =(F_Plateau p);

    ~F_Plateau();

public:

    /**
    *   @fn static void init(int nbCases, bool isProcedural=false)
    *
    *   Constructeur
    *
    *   @param nbCases Nombre de cases du plateau
    *   @param isProcedural Génère le plateau de manière procedural s'il est mis a Vrai
    */
    static void init(int nbCases, bool isProcedural=false);
    static F_Plateau * getInstance();           /**< Renvoie le singleton */
    static void detruire();                     /**< Détruit le singleton */

    void generationClassique();                 /**< Définir le plateau spécifié dans le sujet */
    //void generationProcedural();              /**< Permet de générer un plateau aléatoirement */
    unsigned int taille();                      /**< Renvoie sa taille */
    F_Case& operator [](unsigned int index);    /**< Acces à une case */
};

#endif // PLATEAU_HPP


#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include "F_Pion.hpp"

class F_Case;

/// @todo Faire la génération procédurale du plateau
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

    static void init(int nbCases, bool isProcedural=false);
    static F_Plateau * getInstance();
    static void detruire();

    void generationClassique();     // Définir le plateau spécifié dans le sujet
    void generationProcedural();    // Permet de générer un plateau aléatoirement
    unsigned int taille();
    F_Case& operator [](unsigned int index);
};

#endif // PLATEAU_HPP


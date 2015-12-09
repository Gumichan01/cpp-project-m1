
#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>

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
    F_Plateau * getInstance();
    void generationClassique();     // Définir le plateau spécifié dans le sujet
    void generationProcedural();    // Permet de générer un plateau aléatoirement
    static void detruire();

    F_Case& operator [](unsigned int index);
};

#endif // PLATEAU_HPP


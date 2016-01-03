#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <vector>
#include <string>

class F_Pion;

class F_Joueur
{
    static int id_compteur;

protected:

    int id;                         /**< Identifiant du joueur */
    std::string nom;                /**< Nom du joueur */
    std::vector<F_Pion> pions;      /**< Ses pions */

public:

    /**
    *   @fn F_Joueur(std::string n, int nbPions = 1, int sc = 0)
    *
    *   Constructeur
    *
    *   @param n Nom du joueur
    *   @param nbPions Nombre de pions à donner au joueur
    *   @param sc Score du joueur
    */
    F_Joueur(std::string n, int nbPions = 1);

    virtual void jouer() = 0;   // le joueur joue
    virtual bool gagne() = 0;   // Vérifie si le joueur gagne

    std::string getNom();                   /**< Récupère le nom */
    int getPosition();                      /**< Récupère sa position (celle du premier pion) */
    int getScore();                         /**< Score */
    const std::vector<F_Pion>& getPions();  /**< Récupérer la liste des pions */

    virtual ~F_Joueur();
};

#endif

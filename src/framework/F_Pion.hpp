#ifndef PION_HPP
#define PION_HPP

class F_Pion
{
    static int id_compteur;
    int id;
    int idJoueur;   /* Identifiant du joueur qui possède le pion */
    int position;   /* Position du pion sur le plateau */

public:

    /**
    *   @fn F_Pion(int idJ)
    *
    *   Constructeur
    *
    *   @param idJ Id du joueur
    */
    F_Pion(int idJ);

    /**
    *   @fn F_Pion(const F_Pion& p)
    *
    *   Constructeur de copie
    *
    *   @param p pion à copier
    */
    F_Pion(const F_Pion& p);
    F_Pion& operator=(F_Pion p);    /**< Affectation */

    int getID();                    /**< Renvoie l'id du pion */
    int getIdJoueur();              /**< Renvoie l'id du possesseur */
    int getPosition();              /**< Renvoie sa position sur le plateau */
    void setPosition(int pos);      /**< Change sa position */

    ~F_Pion();
};

#endif // PION_HPP


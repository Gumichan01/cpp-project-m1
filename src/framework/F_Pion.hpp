
#ifndef PION_HPP
#define PION_HPP

class F_Pion
{
    static int id_compteur;
    int id;
    int idJoueur;   /* Identifiant du joueur qui possède le pion */
    int position;   /* Position du pion sur le plateau */

public:

    F_Pion(int idJ);
    F_Pion(const F_Pion& p);
    F_Pion& operator=(F_Pion p);

    int getID();
    int getIdJoueur();
    int getPosition();
    void setPosition(int pos);

    ~F_Pion();
};

#endif // PION_HPP


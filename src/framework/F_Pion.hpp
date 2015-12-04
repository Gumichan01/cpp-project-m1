
#ifndef PION_HPP
#define PION_HPP

class F_Pion
{
    static int id_compteur;
    int id;
    int idJoueur;   /* Identifiant du joueur qui possède le pion*/
    int position;   /* Position du pion sur le plateau */

public:

    F_Pion(int idJ);

    int getID();
    int getIdJoueur();
    int getPosition();
    void setPosition(int id);

    ~F_Pion();
};

#endif // PION_HPP

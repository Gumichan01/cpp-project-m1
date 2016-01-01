
#include <iostream>
#include "F_Case.hpp"


F_Case::F_Case(TYPE_CASE ty, int ref_) : type(ty),ref_case(ref_),vide(true)
{
    // Empty
}


// Ajoute un pion dans la liste des pions présents
void F_Case::ajoutPion(F_Pion& p)
{
    pions[p.getIdJoueur()] = &p;

    std::cout << "Pions : " << pions[p.getIdJoueur()]->getID()
              << " | " << pions[p.getIdJoueur()]->getIdJoueur() << std::endl;

    if(vide == true)
        vide = false;
}


// Enlève un pion dans la liste des pions présents
void F_Case::enleverPion(int idPion)
{
    std::cout << "HUM BEFORE " << pions.size() << std::endl;
    pions.erase(idPion);

    std::cout << "HUM AFTER " << pions.size() << std::endl;

    if(pions.empty())
        vide = true;
}


// Obtenir l'indice la case vers où faire le saut
int F_Case::getSautCase()
{
    return ref_case;
}


// Obtenir le type de la case
TYPE_CASE F_Case::getType()
{
    return type;
}


// Test si la case est vide
bool F_Case::estVide()
{
    return vide;
}


int F_Case::getJoueur()
{
    std::map<int,F_Pion*>::iterator it = pions.begin();
    return it->second->getIdJoueur();
}


F_Case::~F_Case()
{
    // Empty
}


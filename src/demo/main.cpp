

#include <iostream>
#include <string>
#include <cstdlib>

#include "JeuSerpentEchelle.hpp"
#include "JeuPedago.hpp"
#include "JeuMultiPion.hpp"


using namespace std;

void usage(string exec);


int main(int argc,char **argv)
{
    string option;
    F_Jeu * jeu = nullptr;

    if(argc < 2)
    {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    // On récupère l'option
    option = argv[1];

    if(option.size() != 2)
    {
        cerr << "Invalid option : " << option << endl;
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    // option est bien de taille 2
    switch(option[1])
    {
        case '1':   jeu = new JeuSerpentEchelle();
                    break;

        case '2':   jeu = new JeuPedago();
                    break;

        case '3':   jeu = new JeuMultiPion();
                    break;

        case '4':   // Créer le jeu de cartes
                    break;

        case '5':   // Créer le Numéri
                    break;

        default : break;
    }

    // Jouer
    if(jeu == nullptr)
    {
        cerr << "Not implemented yet " << endl;
        return EXIT_FAILURE;
    }

    // On fixe la graine pour la génération de nombres aléatoires
    srand(time(nullptr));

    // Lancer le jeu
    jeu->demarrer();
    jeu->lancerPartie();
    jeu->arret();

    delete jeu;

    return EXIT_SUCCESS;
}

void usage(string exec)
{
    cerr << "Usage : " << exec.c_str() << " -[1|2|3|4|5]" << endl;
    cerr << "-1 : Jeu de base (beta)" << endl;
    cerr << "-2 : Jeu à variante pédagogique (pas encore disponible) " << endl;
    cerr << "-3 : Jeu à plusieurs pions (pas encore disponible) " << endl;
    cerr << "-4 : Jeu sans dés, avec cartes (indisponible)" << endl;
    cerr << "-5 : Numeri (indisponible)" << endl;
}



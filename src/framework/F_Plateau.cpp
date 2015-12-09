

#include "F_Case.hpp"
#include "F_Plateau.hpp"


static F_Plateau *singleton = nullptr;

F_Plateau::F_Plateau(int nbCases,bool isProcedural)
    : cases(nbCases)
{
    if(isProcedural)
        generationProcedural();
    else
        generationClassique();
}

F_Plateau::~F_Plateau()
{
    for(std::vector<F_Case *>::size_type i = 0; i != cases.size(); i++)
    {
        delete cases[i];
        cases.erase(cases.begin() + i);
        i--;
    }
}

void F_Plateau::init(int nbCases, bool isProcedural)
{
    if(singleton == nullptr)
        singleton = new F_Plateau(nbCases,isProcedural);
}

F_Plateau * getInstance()
{
    return singleton;
}


void F_Plateau::detruire()
{
    delete singleton;
}


void F_Plateau::generationClassique()
{
    // 10 échelles et 10 serpents
    for(std::vector<F_Case *>::size_type i = 0; i != cases.size(); i++)
    {
        switch(i)
        {
            case 2  :   cases[i] = new F_Case(TYPE_CASE::SAUT,18);
                        break;

            case 8  :   cases[i] = new F_Case(TYPE_CASE::SAUT,50);
                        break;

            case 10 :   cases[i] = new F_Case(TYPE_CASE::SAUT,30);
                        break;

            // Serpent
            case 16 :   cases[i] = new F_Case(TYPE_CASE::SAUT,6);
                        break;

            // Serpent
            case 22 :   cases[i] = new F_Case(TYPE_CASE::SAUT,20);
                        break;

            case 26 :   cases[i] = new F_Case(TYPE_CASE::SAUT,74);
                        break;

            // Serpent
            case 32 :   cases[i] = new F_Case(TYPE_CASE::SAUT,6);
                        break;

            case 40 :   cases[i] = new F_Case(TYPE_CASE::SAUT,60);
                        break;

            case 44 :   cases[i] = new F_Case(TYPE_CASE::SAUT,64);
                        break;

            // Serpent
            case 48 :   cases[i] = new F_Case(TYPE_CASE::SAUT,28);
                        break;

            case 52 :   cases[i] = new F_Case(TYPE_CASE::SAUT,70);
                        break;

            // Serpent
            case 58 :   cases[i] = new F_Case(TYPE_CASE::SAUT,24);
                        break;

            case 68 :   cases[i] = new F_Case(TYPE_CASE::SAUT,94);
                        break;

            case 78 :   cases[i] = new F_Case(TYPE_CASE::SAUT,100);
                        break;

            // Serpent
            case 80 :   cases[i] = new F_Case(TYPE_CASE::SAUT,42);
                        break;

            case 84 :   cases[i] = new F_Case(TYPE_CASE::SAUT,96);
                        break;

            // Serpent
            case 86 :   cases[i] = new F_Case(TYPE_CASE::SAUT,36);
                        break;

            // Serpent
            case 92 :   cases[i] = new F_Case(TYPE_CASE::SAUT,72);
                        break;

            // Serpent
            case 98 :   cases[i] = new F_Case(TYPE_CASE::SAUT,62);
                        break;

            default :   cases[i] = new F_Case(TYPE_CASE::NORMAL);
                        break;
        }
    }
}


void F_Plateau::generationProcedural()
{
    /// @todo Génération procédural du plateau
}


F_Case& F_Plateau::operator [](unsigned int index)
{
    return *(this->cases.at(index));
}



#ifndef STRAT_HPP
#define STRAT_HPP


class F_JoueurIA;

class Strategie
{

public :

    virtual void executer() = 0;
    virtual ~Strategie();
};

/// @todo execution
class F_StrategieIA : virtual public Strategie
{
protected:
    F_JoueurIA * ia;

public:

    F_StrategieIA(F_JoueurIA * j);

    virtual ~F_StrategieIA();
};

#endif // STRAT_HPP



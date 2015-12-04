
#ifndef STRAT_HPP
#define STRAT_HPP


class JoueurIA;

class Strategie
{

public :

    virtual void executer() = 0;
    virtual ~Strategie();
};


class StrategieIA : virtual public Strategie
{
protected:
    JoueurIA * ia;

public:

    StrategieIA(JoueurIA * j);

    virtual ~StrategieIA();
};

#endif // STRAT_HPP



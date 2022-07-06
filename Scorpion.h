#ifndef Scorpion_h
#define Scorpion_h
#include "Animal.h"

class Scorpion : public Animal
{
private:
    int deamage = 1;
public:
    Scorpion();
    //Scorpion(float x, float y);
    ~Scorpion();

};

#endif
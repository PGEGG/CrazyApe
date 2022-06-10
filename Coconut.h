#ifndef Coconut_h
#define Coconut_h
#include "Item.h"

class Coconut : public Item {
private:
    int deamage;
public:
    Coconut();
    Coconut(int y);
    ~Coconut();
    void Fly();


};
#endif
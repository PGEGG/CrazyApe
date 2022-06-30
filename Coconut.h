#pragma once
#include "Item.h"

class Coconut : public Item {
private:
    int deamage = 1;
    int direction = 1;
public:
    Coconut();
    Coconut(float x, float y, int i);
    ~Coconut();
    void flyCoconut();


};

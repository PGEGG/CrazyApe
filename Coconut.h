#pragma once
#include "Item.h"

class Coconut : public Item {
private:
    int damage = 1;
    int direction = 1;
public:
    Coconut();
    Coconut(float x, float y, int i);
    ~Coconut();
    void flyCoconut();


};

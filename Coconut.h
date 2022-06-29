#pragma once
#include "Item.h"

class Coconut : public Item {
private:
    int deamage;
public:
    Coconut();
    Coconut(float x, float y);
    ~Coconut();
    void Fly();


};

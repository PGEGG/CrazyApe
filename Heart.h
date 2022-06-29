#pragma once
#include "Item.h"

class Heart: public Item
{
private:
    
    int lifetime;
public:
    Heart();
    Heart(float x, float y);
    ~Heart();

};
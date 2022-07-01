#ifndef Animal_h
#define Animal_h
#include <SFML/Graphics.hpp>
#include "Item.h"
#include <iostream>

class Animal: public Item
{
protected:
    int getDirection();

public:
    Animal();
    virtual ~Animal() = 0;
    virtual void move();
};


#endif
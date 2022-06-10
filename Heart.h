#ifndef Heart_h
#define Heart_h
#include "Item.h"

class Heart: public Item
{
private:
    int lifetime;
public:
    Heart();
    Heart(int x, int y);
    ~Heart();
};

#endif
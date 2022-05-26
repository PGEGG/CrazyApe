#ifndef Tiger_h
#define Tiger_h
#include "Animal.h"

class Tiger : public Animal
{
private:
    int lifetime = 0;
public:
    Tiger();
    ~Tiger();
};


#endif
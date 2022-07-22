#ifndef Tiger_h
#define Tiger_h
#include "Animal.h"

class Tiger : public Animal
{
private:
    int damage = 5;
    int lifetime = 0;
    
public:
    
    Tiger();
    //Tiger(float x, float y);
    ~Tiger();
    //changes
    const sf::Sprite Object;
};

#endif
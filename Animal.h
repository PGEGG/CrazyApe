#ifndef Animal_h
#define Animal_h
#include <SFML/Graphics.hpp>

class Animal
{
protected:
    float posX = 0;
    float posY = 0;

    // create Heart
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Animal();
    virtual ~Animal() = 0;
    virtual void move(float x, float y);

    sf::RectangleShape animalShape;
    float animalWidth = 20.f;
    float animalHeight = 20.f;
};


#endif
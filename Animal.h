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

    sf::Time timePerFrame = sf::seconds(1.f/5.f);
    int getDirection();

public:
    Animal();
    virtual ~Animal() = 0;
    virtual void move();

    sf::RectangleShape animalShape;
    float animalWidth = 30.f;
    float animalHeight = 30.f;

    sf::Clock clock; 
    sf::Time accumulator = sf::Time::Zero; 
};


#endif
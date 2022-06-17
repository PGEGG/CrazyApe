
#include "Gui.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

Gui::Gui()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "CrazyApe.exe");

    // Load image
    sf::Image image;
    if ((image.loadFromFile("images\\APE.png")) == false );
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    sf::Texture texture;
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
    texture.loadFromImage(image);

    // create Shape
    sf::RectangleShape shape(sf::Vector2(50.f,80.f));
    shape.setTexture(&texture);
    //shape.setFillColor(sf::Color(255, 255, 255, 255));
    shape.setPosition(50, 10);

    // Texture to Sprite
    sf::Sprite sprite(texture);
    
    // Färbe Sprite mit RGB Farbe
    sprite.setColor(sf::Color(205, 102, 29));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(139,139,0)); // clear screen
        window.draw(shape);
        window.display();  // update the window
    }
    
}

Gui::~Gui()
{

}

void Gui::setField(int *field[])
{

}

void Gui::info_button()
{

}

void Gui::start_button()
{

}

void Gui::stop_button()
{

}

void Gui::reset_button()
{

}

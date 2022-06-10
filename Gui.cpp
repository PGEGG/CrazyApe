
#include "Gui.h"
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;

Gui::Gui()
{
    sf::RenderWindow window(sf::VideoMode(310, 163), "CrazyApe.exe");

    // Load image
    sf::Image image;
    if ((image.loadFromFile("CrazyApe.png")) == false );
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    sf::Texture texture;
    texture.loadFromImage(image);

    // Texture to Sprite
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(); // clear screen
        window.draw(sprite);    // display Sprite "Image" on window
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

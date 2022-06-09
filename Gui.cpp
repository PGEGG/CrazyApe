
#include "Gui.h"
#include <iostream>
#include <SFML/Graphics.hpp>


using namespace std;

Gui::Gui()
{
    sf::RenderWindow window(sf::VideoMode(500, 400), "CrazyApe");
    sf::CircleShape shape(5.f);
    shape.setFillerColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    
    
}
Gui::~Gui()
{

}

void Gui::setField()
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

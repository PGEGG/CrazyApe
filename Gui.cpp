
#include <iostream>
#include "Gui.h"
#include "Gamecontroller.h"
using namespace std;

Gui::Gui()
{

    this->initVariables();
    this->initWindow();

}

// deconstructor deletes windowpointer
Gui::~Gui()
{
    delete this->window;
}

// constructor generates a windowpointer and refers to nullpointer
void Gui::initVariables()
{
    this->window = nullptr;
}

// This function generates a window (Gui) with its size and title
void Gui::initWindow()
{
    this->videoMode.height = 400;
    this->videoMode.width = 600;
    this->window = new sf::RenderWindow(this->videoMode, "CrazyApe.exe");

}

// This function refers to the pollEvent function
void Gui::update()
{
    this->pollEvents();
}

// This function renders the window with a rgb-color, draws the shape and display it on the screen
void Gui::render()
{
    this->window->clear(sf::Color(139,139,0));
    this->window->draw(shape);
    this->window->display();
}

// This function checks if there is a Mouse or Keyboard event an the window
void Gui::pollEvents()
{
    sf::Event event;
        while (this->window->pollEvent(this->event))
        {
            if (this->event.type == sf::Event::Closed){ // close window if red "X" is clicked
                this->window->close();
            }else if (this->event.type == sf::Event::KeyPressed)
            {    // moves the Ape (player) with "wasd" or "arrow keys"
                if ((this->event.key.code == sf::Keyboard::Left) || (this->event.key.code == sf::Keyboard::A))
                {
                    shape.move(-10.f, 0.f);
                }else if ((this->event.key.code == sf::Keyboard::Right) || (this->event.key.code == sf::Keyboard::D))
                {
                    shape.move(+10.f, 0.f);
                }else if ((this->event.key.code == sf::Keyboard::Down) || (this->event.key.code == sf::Keyboard::S))
                {
                    shape.move(0.f, +10.f);
                }else if ((this->event.key.code == sf::Keyboard::Up) || (this->event.key.code == sf::Keyboard::W))
                {
                    shape.move(0.f, -10.f);
                }//end if-moving
            }// end if-event
        }
}

// checks if the window is running
const bool Gui::running()
{
    return this->window->isOpen();
}

//  This function sets the setup for the "startwindow" and updates, renders window while its running
void Gui::checkWindow(){

    if (guiCounter == 0)
    {
    // Load image
    
    if (!(image.loadFromFile("images\\APE.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    texture.setSmooth(true);
    texture.loadFromImage(image);

    // declarate Shape
    shape.setSize(sf::Vector2(50.f,80.f));
    shape.setTexture(&texture);
    shape.setPosition(50, 10);

    // Texture to Sprite
    sprite.setTexture(texture);
    
    // setcolor from sprite with RGB
    sprite.setColor(sf::Color(205, 102, 29));
    }
    

    while (this->running())
    {
        this->update();
        this->render();
    }

    guiCounter++;
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

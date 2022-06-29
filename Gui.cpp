
#include <iostream>
#include "Gui.h"
#include "Gamecontroller.h"

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
                    shapeApe.move(-10.f, 0.f);
                }else if ((this->event.key.code == sf::Keyboard::Right) || (this->event.key.code == sf::Keyboard::D))
                {
                    shapeApe.move(+10.f, 0.f);
                }else if ((this->event.key.code == sf::Keyboard::Down) || (this->event.key.code == sf::Keyboard::S))
                {
                    shapeApe.move(0.f, +10.f);
                }else if ((this->event.key.code == sf::Keyboard::Up) || (this->event.key.code == sf::Keyboard::W))
                {
                    shapeApe.move(0.f, -10.f);
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
        this->createJungle();
        this->createApe();
        this->createTiger();
        //this->createHeart();
        //this->createCoconut();
        this->createBananatree();
        //this->createBanana();
        this->createHome();
        this->openManpage();
    }
    

    while (this->running())
    {
        this->update();
        this->render();
    }

    guiCounter++;
}

// This function renders the window with a rgb-color, draws the shape and display it on the screen
void Gui::render()
{
    this->window->clear(sf::Color(139,139,0));
    this->window->draw(shapeJungle);
    this->window->draw(shapeHome);
    this->window->draw(shapeApe);
    this->window->draw(shapeTiger);
    this->window->draw(myHeart->itemShape);
    this->window->draw(myCoconut->itemShape);
    this->window->draw(shapeBananatree);
    this->window->draw(myBanana->itemShape);
    this->window->display();
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

void Gui::createApe()
{
    // Load imageApe
    if (!(imageApe.loadFromFile("images\\APE.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    textureApe.setSmooth(true);
    textureApe.loadFromImage(imageApe);

    // declarate Shape
    shapeApe.setSize(sf::Vector2(50.f,80.f));
    shapeApe.setTexture(&textureApe);
    shapeApe.setPosition(70, this->videoMode.height-80);

    // Texture to Sprite
    spriteApe.setTexture(textureApe);
    
    // setcolor from spriteApe with RGB
    spriteApe.setColor(sf::Color(205, 102, 29));
}// end createApe

void Gui::createTiger()
{
    if (!(imageTiger.loadFromFile("images\\TIGER.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    textureTiger.setSmooth(true);
    textureTiger.loadFromImage(imageTiger);

    // declarate Shape
    shapeTiger.setSize(sf::Vector2(50.f,80.f));
    shapeTiger.setTexture(&textureTiger);
    shapeTiger.setPosition(this->videoMode.width/2-50, this->videoMode.height/2-80);

    // Texture to Sprite
    spriteTiger.setTexture(textureTiger);
    
    // setcolor from spriteApe with RGB
    spriteTiger.setColor(sf::Color(205, 102, 29));

}// end createTiger
/*
void Gui::createHeart()
{
    if (!(imageHeart.loadFromFile("images\\HEART.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    textureHeart.setSmooth(true);
    textureHeart.loadFromImage(imageHeart);

    // declarate Shape
    shapeHeart.setSize(sf::Vector2(20.f,20.f));
    shapeHeart.setTexture(&textureHeart);
    shapeHeart.setPosition(200, 200);

    // Texture to Sprite
    spriteHeart.setTexture(textureHeart);
    
    // setcolor from spriteApe with RGB
    spriteHeart.setColor(sf::Color(205, 102, 29));

}// end createHeart

void Gui::createCoconut()
{
    if (!(imageCoconut.loadFromFile("images\\COCONUT.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    textureCoconut.setSmooth(true);
    textureCoconut.loadFromImage(imageCoconut);

    // declarate Shape
    shapeCoconut.setSize(sf::Vector2(20.f,20.f));
    shapeCoconut.setTexture(&textureCoconut);
    shapeCoconut.setPosition(300, 200);

    // Texture to Sprite
    spriteCoconut.setTexture(textureCoconut);
    
    // setcolor from spriteApe with RGB
    spriteCoconut.setColor(sf::Color(205, 102, 29));

}// end createCoconut
*/
void Gui::createBananatree()
{
    if (!(imageBananatree.loadFromFile("images\\BANANATREE.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    textureBananatree.setSmooth(true);
    textureBananatree.loadFromImage(imageBananatree);

    // declarate Shape
    shapeBananatree.setSize(sf::Vector2(80.f,80.f));
    shapeBananatree.setTexture(&textureBananatree);
    shapeBananatree.setPosition(100, 200);

    // Texture to Sprite
    spriteBananatree.setTexture(textureBananatree);
    
    // setcolor from spriteApe with RGB
    spriteBananatree.setColor(sf::Color(205, 102, 29));

}// end createBananatree
/*
void Gui::createBanana()
{
    if (!(imageBanana.loadFromFile("images\\BANANA.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    textureBanana.setSmooth(true);
    textureBanana.loadFromImage(imageBanana);

    // declarate Shape
    shapeBanana.setSize(sf::Vector2(20.f,20.f));
    shapeBanana.setTexture(&textureBanana);
    shapeBanana.setPosition(200, 250);

    // Texture to Sprite
    spriteBanana.setTexture(textureBanana);
    
    // setcolor from spriteApe with RGB
    spriteBanana.setColor(sf::Color(205, 102, 29));

}// end createBanana
*/

void Gui::createHome()
{
    if (!(imageHome.loadFromFile("images\\HOME.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    textureHome.setSmooth(true);
    textureHome.loadFromImage(imageHome);

    // declarate Shape
    shapeHome.setSize(sf::Vector2(100.f,120.f));
    shapeHome.setTexture(&textureHome);
    shapeHome.setPosition(0, this->videoMode.height-120);

    // Texture to Sprite
    spriteHome.setTexture(textureHome);
    
    // setcolor from spriteApe with RGB
    spriteHome.setColor(sf::Color(205, 102, 29));

}// end createHome

void Gui::createJungle()
{
    if (!(imageJungle.loadFromFile("images\\JUNGLE.png")));
    {
        std::cerr << "Can`t load image!";
    }

    // Give Image to texture
    // Glättet die Pixel (Schärft das Bild)
    textureJungle.setSmooth(true);
    textureJungle.loadFromImage(imageJungle);

    // declarate Shape
    shapeJungle.setSize(sf::Vector2(600.f,400.f));
    shapeJungle.setTexture(&textureJungle);
    shapeJungle.setPosition(0, 0);

    // Texture to Sprite
    spriteJungle.setTexture(textureJungle);
    
    // setcolor from spriteApe with RGB
    spriteJungle.setColor(sf::Color(205, 102, 29));

}// end createJungle

void Gui::openManpage()
{   
    
    if (!font_comic.loadFromFile("fonts\\comic.ttf"))
    {
        std::cerr << "Unable to load Font!" << std::endl;
    }
    /*
    FILE* manpage = nullptr;
    if (fopen(manpage, "files\\manpage.txt"))
    {
        std::cerr << "Unable to load manpage!" << std::endl;
    }

    while (std::getline(manpage, txt_line))
    {
        txt_line += "\n";
    }
*/
    txt_manpage.setString("Test");
    txt_manpage.setCharacterSize(12);
    txt_manpage.setFont(font_comic);
    this->window->draw(txt_manpage);
}// end openManpage
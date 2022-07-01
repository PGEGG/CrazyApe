
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
    if (!(icon.loadFromFile("images\\ICON.png")))
    {
        std::cerr << "Can`t load image_icon!" << std::endl;
    }
    
    this->videoMode.height = 400;
    this->videoMode.width = 600;
    this->window = new sf::RenderWindow(this->videoMode, "CrazyApe.exe");
    this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

// This function refers to the pollEvent function
void Gui::update()
{
    this->pollEvents();
    this->allCoconutsFly();
    this->checkMyBorders();
}
void Gui::checkMyBorders(){
    this->checkBorderPlayer();
    this->checkBorderAnimal(this->myScorpion);
    this->checkBorderAnimal(this->myScorpion2);
    this->checkBorderAnimal(this->myScorpion3);
    this->checkBorderAnimal(this->myTiger);
}
void Gui::allCoconutsFly(){
    this->myCoconut->flyCoconut();
    this->myCoconut2->flyCoconut();
    this->myCoconut3->flyCoconut();
    this->myCoconut4->flyCoconut();
    this->myCoconut5->flyCoconut();
    this->myScorpion->move();
    this->myScorpion2->move();
    this->myScorpion3->move();
    this->myTiger->move();
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
                    myPlayer->itemShape.move(-5.f, 0.f);
                }else if ((this->event.key.code == sf::Keyboard::Right) || (this->event.key.code == sf::Keyboard::D))
                {
                    myPlayer->itemShape.move(+5.f, 0.f);
                }else if ((this->event.key.code == sf::Keyboard::Down) || (this->event.key.code == sf::Keyboard::S))
                {
                    myPlayer->itemShape.move(0.f, +5.f);
                }else if ((this->event.key.code == sf::Keyboard::Up) || (this->event.key.code == sf::Keyboard::W))
                {
                    myPlayer->itemShape.move(0.f, -5.f);
                }//end if-moving
            }// end if-event
        }
}
void Gui::checkBorderAnimal(Animal *animal){
    if (animal->itemShape.getPosition().x <= -12.f){
        animal->itemShape.setPosition(-12.f, animal->itemShape.getPosition().y);
    } //Left
    else if(animal->itemShape.getPosition().x >= this->videoMode.width - animal->itemWidth){
        animal->itemShape.setPosition(this->videoMode.width - animal->itemWidth, animal->itemShape.getPosition().y);
    } //Right
    else if (animal->itemShape.getPosition().y <= 0.f){
        animal->itemShape.setPosition(animal->itemShape.getPosition().x, 0.f);
    } //Top
    else if (animal->itemShape.getPosition().y >= this->videoMode.height - animal->itemHeight){
        animal->itemShape.setPosition(animal->itemShape.getPosition().x, this->videoMode.height - animal->itemHeight);
    } //Bottom
}
void Gui::checkBorderPlayer(){
    if (myPlayer->itemShape.getPosition().x <= -12.f){
        myPlayer->itemShape.setPosition(-10.f, myPlayer->itemShape.getPosition().y);
    } //Left
    else if(myPlayer->itemShape.getPosition().x >= this->videoMode.width - myPlayer->itemWidth){
        myPlayer->itemShape.setPosition(this->videoMode.width - myPlayer->itemWidth-5.f, myPlayer->itemShape.getPosition().y);
    } //Right
    else if (myPlayer->itemShape.getPosition().y <= 0.f){
        myPlayer->itemShape.setPosition(myPlayer->itemShape.getPosition().x, 5.f);
    } //Top
    else if (myPlayer->itemShape.getPosition().y >= this->videoMode.height - myPlayer->itemHeight){
        myPlayer->itemShape.setPosition(myPlayer->itemShape.getPosition().x,this->videoMode.height - myPlayer->itemHeight-5.f);
    } //Bottom
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
        //this->createApe();
        //this->createTiger();
        //this->createHeart();
        //this->createCoconut();
        //this->createBananatree();
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
void Gui::resetCocoClock(){
    this->myCoconut->framecounter+= this->myCoconut->clock.restart();
    this->myCoconut2->framecounter+= this->myCoconut2->clock.restart();
    this->myCoconut3->framecounter+= this->myCoconut3->clock.restart();
    this->myCoconut4->framecounter+= this->myCoconut4->clock.restart();
    this->myCoconut5->framecounter+= this->myCoconut5->clock.restart();
    this->myScorpion->framecounter+= this->myScorpion->clock.restart();
    this->myScorpion2->framecounter+= this->myScorpion2->clock.restart();
    this->myScorpion3->framecounter+= this->myScorpion3->clock.restart();
    this->myTiger->framecounter+= this->myTiger->clock.restart();
}

// This function renders the window with a rgb-color, draws the shape and display it on the screen
void Gui::render()
{
    this->resetCocoClock();
    this->window->clear(sf::Color(139,139,0));
    this->window->draw(shapeJungle);
    this->window->draw(shapeHome);
    this->window->draw(myPlayer->itemShape);
    this->window->draw(myTiger->itemShape);
    this->window->draw(myScorpion->itemShape);
    this->window->draw(myScorpion2->itemShape);
    this->window->draw(myScorpion3->itemShape);
    this->window->draw(myHeart->itemShape);
    this->window->draw(myCoconut->itemShape);
    this->window->draw(myCoconut2->itemShape);
    this->window->draw(myCoconut3->itemShape);
    this->window->draw(myCoconut4->itemShape);
    this->window->draw(myCoconut5->itemShape);
    this->window->draw(myTree->itemShape);
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
/*
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
        std::cerr << "Can`t load image_home!" << std::endl;
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
        std::cerr << "Can`t load image_jungle!" << std::endl;
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
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
    this->checkObjBorder(this->myPlayer);
    this->checkObjBorder(this->myScorpion);
    this->checkObjBorder(this->myScorpion2);
    this->checkObjBorder(this->myScorpion3);
    this->checkObjBorder(this->myTiger);
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
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A ) )
                {
                    myPlayer->sprite.move( -5.f, 0 );
                }
                else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D )) 
                {
                    myPlayer->sprite.move( 5.f, 0 );
                }
                
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W ) )
                {
                    myPlayer->sprite.move( 0, -5.f );
                }
                else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S ) )
                {
                    myPlayer->sprite.move( 0, 5.f );
                }
            }// end if-event
        }
}

void Gui::checkObjBorder(Item *object){
    if (object->sprite.getPosition().x <= -12.f){
        object->sprite.setPosition(-10.f, object->sprite.getPosition().y);
    } //Left
    else if(object->sprite.getPosition().x >= this->videoMode.width - object->itemWidth){
        object->sprite.setPosition(this->videoMode.width - object->itemWidth-5.f, object->sprite.getPosition().y);
    } //Right
    else if (object->sprite.getPosition().y <= 0.f){
        object->sprite.setPosition(object->sprite.getPosition().x, 5.f);
    } //Top
    else if (object->sprite.getPosition().y >= this->videoMode.height - object->itemHeight){
        object->sprite.setPosition(object->sprite.getPosition().x,this->videoMode.height - object->itemHeight-5.f);
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
        this->createHome();
        this->openManpage();
    }
    

    while (this->running())
    {
        this->update();
        this->render();
        this->proofe_collision();
    }

    guiCounter++;
}

//changes for collision method
void Gui::proofe_collision(){
    if ( Collision::PixelPerfectTest(myPlayer->sprite, myTiger->sprite ) )
    {
        std::cout << "Collision" << std::endl;
    }
    else
    {
        std::cout << "No Collision" << std::endl;
    }
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
    this->window->draw(myPlayer->sprite);
    this->window->draw(myTiger->sprite);

    this->window->draw(myScorpion->sprite);
    this->window->draw(myScorpion2->sprite);
    this->window->draw(myScorpion3->sprite);
    this->window->draw(myHeart->sprite);
    this->window->draw(myCoconut->sprite);
    this->window->draw(myCoconut2->sprite);
    this->window->draw(myCoconut3->sprite);
    this->window->draw(myCoconut4->sprite);
    this->window->draw(myCoconut5->sprite);
    this->window->draw(myTree->sprite);
    this->window->draw(myBanana->sprite);
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
#include <iostream>
#include "Gui.h"
#include "Gamecontroller.h"

/**
 * @brief Construct a new Gui:: Gui object
 * call initVariables() and initWindow()
 */
Gui::Gui()
{
    this->initVariables();
    this->initWindow();
}

/**
 * @brief delete object Gui and this window
 *  
 */
Gui::~Gui()
{
    delete this->window;
}


/**
 * @brief constructor generates a windowpointer and refers to nullpointer
 * 
 */
void Gui::initVariables()
{
    this->window = nullptr;
}

/**
 * @brief This function generates a window (Gui) with its size and title
 * 
 */
void Gui::initWindow()
{
    if (!icon.loadFromFile("images\\ICON.png"))
    {
        std::cerr << "Can`t load image_icon!" << std::endl;
    }
    
    this->videoMode.height = 400;
    this->videoMode.width = 600;
    this->window = new sf::RenderWindow(this->videoMode, "CrazyApe.exe");
    this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

/**
 * @brief This function checks events 
 * 
 */
void Gui::update()
{
    this->pollEvents();
    this->moveObjects();
    this->checkMyBorders();
}

/**
 * @brief this function checks if any object will leave the window in the next step
 * 
 */
void Gui::checkMyBorders(){
    this->checkObjBorder(this->myPlayer);
    this->checkObjBorder(this->myScorpion);
    this->checkObjBorder(this->myScorpion2);
    this->checkObjBorder(this->myScorpion3);
    this->checkObjBorder(this->myTiger);
}

/**
 * @brief this function moves all Objects 
 * moves coconuts
 * move scorpions
 * moves Tiger
 */
void Gui::moveObjects(){
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

/**
 * @brief This function checks if there is a Mouse or Keyboard event an the window
 * proofe wasd or up, down, left, right
 * proofe if window was closed
 */
void Gui::pollEvents()
{
    sf::Event event;
        while (this->window->pollEvent(this->event))
        {
            /// close window if red "X" is clicked
            if (this->event.type == sf::Event::Closed){ 
                this->window->close();
            }

            /// moves the Ape (player) with "wasd" or "arrow keys"
            else if (this->event.type == sf::Event::KeyPressed)
            {    
                /// Left
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A ) )
                {
                    myPlayer->sprite.move( -5.f, 0 );
                }

                /// Right
                else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D )) 
                {
                    myPlayer->sprite.move( 5.f, 0 );
                }
                
                /// Up
                if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W ) )
                {
                    myPlayer->sprite.move( 0, -5.f );
                }

                ///Down
                else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S ) )
                {
                    myPlayer->sprite.move( 0, 5.f );
                }
            }
        }
}

/**
 * @brief this function checks if the passed Object will leave the window
 * 
 * @param object every Object of Item that moves in the window can be passed
 */
void Gui::checkObjBorder(Item *object)
{
    ///Left
    if (object->sprite.getPosition().x <= -12.f){
        object->sprite.setPosition(-10.f, object->sprite.getPosition().y);
    }

    ///Right
    else if(object->sprite.getPosition().x >= this->videoMode.width - object->itemWidth){
        object->sprite.setPosition(this->videoMode.width - object->itemWidth-5.f, object->sprite.getPosition().y);
    } 

    ///Top
    else if (object->sprite.getPosition().y <= 0.f){
        object->sprite.setPosition(object->sprite.getPosition().x, 5.f);
    } 

    ///Bottom
    else if (object->sprite.getPosition().y >= this->videoMode.height - object->itemHeight){
        object->sprite.setPosition(object->sprite.getPosition().x,this->videoMode.height - object->itemHeight-5.f);
    } 
}


/**
 * @brief  checks if the window is open
 * 
 * @return true if window is open
 * @return false if window is closed
 */
const bool Gui::running()
{
    return this->window->isOpen();
}

/**
 * @brief This function sets the setup for the "startwindow" and updates, renders window and proofe collision while its running
 * 
 */
void Gui::checkWindow(){
    
    this->createJungle();
    this->createHome();
    this->openManpage();

    while (this->running())
    {
        this->update();
        this->render();
        this->checkCollision();
    }
}


/**
 * @brief this function checks player and the other objects for collision
 * 
 */
void Gui::checkCollision(){
    if ( Collision::PixelPerfectTest(myPlayer->sprite, myTiger->sprite )&&
    (!Collision::PixelPerfectTest(myPlayer->sprite, spriteHome )) )
    {
        std::cout << "Collision Tiger!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()-5);
        myPlayer->sprite.setPosition(70.f, 350.f);
        //delete(myPlayer);
    }else if ((Collision::PixelPerfectTest(myPlayer->sprite, myScorpion->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myScorpion2->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myScorpion3->sprite ))&&
                (!Collision::PixelPerfectTest(myPlayer->sprite, spriteHome )))
    {
        std::cout << "Collision Scorpion!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()-1);
        myPlayer->sprite.setPosition(70.f, 350.f);
    }else if ((Collision::PixelPerfectTest(myPlayer->sprite, myCoconut->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myCoconut2->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myCoconut3->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myCoconut4->sprite ))&&
                (!Collision::PixelPerfectTest(myPlayer->sprite, spriteHome )))
    {
        std::cout << "Collision Coconut!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()-1);
        myPlayer->sprite.setPosition(70.f, 350.f);
    }else if ((Collision::PixelPerfectTest(myPlayer->sprite, myCoconut5->sprite ))&&
    (!Collision::PixelPerfectTest(myPlayer->sprite, spriteHome )))
    {
        std::cout << "Collision Red Coconut!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()-3);
        myPlayer->sprite.setPosition(70.f, 350.f);
    }else if (Collision::PixelPerfectTest(myPlayer->sprite, myHeart->sprite ))
    {
        std::cout << "Collision Heard!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()+1);
        this->myHeart->sprite.setPosition(320.f, 234.f);
        //delete(myHeart);
    }else if (Collision::PixelPerfectTest(myPlayer->sprite, myBanana->sprite ))
    {
        std::cout << "Collision Banana!" << std::endl;
        myPlayer->addBanana();
        std::cout << myPlayer->getBanana() << std::endl;
        this->myBanana->sprite.setPosition(1.f, 1.f);
    }else if (Collision::PixelPerfectTest(myPlayer->sprite, myTree->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myTree2->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myTree3->sprite ))
    {
        std::cout << "Collision Tree!" << std::endl;
        myTree->treeCollision(myPlayer, myTree);
        myTree2->treeCollision(myPlayer, myTree2);
        myTree3->treeCollision(myPlayer, myTree3);
    }else if (Collision::PixelPerfectTest(myPlayer->sprite, spriteHome ))
    {
        std::cout << "Collision Home!" << std::endl;
        std::cout << "You need " << 3 - myPlayer->getBanana() << " to win!" << std::endl;
    }else
    {
        std::cout << "No Collision" << std::endl;
    }
}

/**
 * @brief reset Clock for mooving objects
 * 
 */
void Gui::resetClock(){
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

/**
 * @brief This function renders the window with a rgb-color, draws the shape and sprite and display it on the screen
 * 
 */
void Gui::render()
{
    this->resetClock();
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
    this->window->draw(myTree2->sprite);
    this->window->draw(myTree3->sprite);
    this->window->draw(myBanana->sprite);
    this->window->display();
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

/**
 * @brief this function initialise objet home
 * 
 */
void Gui::createHome()
{
    /// if couldn`t load image
    if (!(imageHome.loadFromFile("images\\HOME.png")));
    {
        std::cerr << "Can`t load image_home!" << std::endl;
    }

    /// Smooths the pixels (Sharpen the image)
    textureHome.setSmooth(true);
    /// Give Image to texture
    textureHome.loadFromImage(imageHome);

    // declarate Shape
    shapeHome.setSize(sf::Vector2(100.f,120.f));
    shapeHome.setTexture(&textureHome);
    shapeHome.setPosition(0, this->videoMode.height-120);

    // declarate Sprite
    spriteHome.setScale(sf::Vector2f(0.5, 0.5));
    spriteHome.setPosition(0, this->videoMode.height-120);

    // Texture to Sprite
    spriteHome.setTexture(textureHome);
}// end createHome

/**
 * @brief this function initialise object jungle
 * 
 */
void Gui::createJungle()
{
    /// if couldn`t load image
    if (!(imageJungle.loadFromFile("images\\JUNGLE.png")));
    {
        std::cerr << "Can`t load image_jungle!" << std::endl;
    }

    /// Smooths the pixels (Sharpen the image)
    textureJungle.setSmooth(true);
    /// Give Image to texture
    textureJungle.loadFromImage(imageJungle);

    // declarate Shape
    shapeJungle.setSize(sf::Vector2f(this->videoMode.width, this->videoMode.height));
    shapeJungle.setTexture(&textureJungle);
    shapeJungle.setPosition(0, 0);

}// end createJungle

/**
 * @brief to do button manpage
 * 
 */
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
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
    
    this->videoMode.height = 622;
    this->videoMode.width = 1024;
    this->window = new sf::RenderWindow(this->videoMode, "CrazyApe.exe");
    this->window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

/**
 * @brief This function checks events 
 * 
 */
void Gui::update()
{
    //this->pollEvents();
    this->moveObjects();
    this->checkMyBorders();
    myMenu->updateBananaHeart(myPlayer);
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
    this->myCoconut->flyCoconut(gamebreak);
    this->myCoconut2->flyCoconut(gamebreak);
    this->myCoconut3->flyCoconut(gamebreak);
    this->myCoconut4->flyCoconut(gamebreak);
    this->myCoconut5->flyCoconut(gamebreak);
    this->myScorpion->move(gamebreak);
    this->myScorpion2->move(gamebreak);
    this->myScorpion3->move(gamebreak);
    this->myTiger->move(gamebreak);
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
            else if (this->event.type == sf::Event::KeyPressed && (!myMenu->getInfo()) && (!myMenu->getPause()))
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
            else if (this->event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

                /// if button play/pause button is clicked
                if (myMenu->playButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    myMenu->pauseclicked();
                }

                /// if button info is clicked
                if (myMenu->infoButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    myMenu->infoclicked();
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
    else if (object->sprite.getPosition().y <= myMenu->menu.getSize().y - 30 ){
        object->sprite.setPosition(object->sprite.getPosition().x, myMenu->menu.getSize().y - 30);
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
        myMenu->checkInfoButton();
        //this->update();
        this->pollEvents();
        //myMenu->checkButtonEvents();
        if ( myMenu->getInfo() || myMenu->getPause() ) {
            gamebreak=true;
            if (count==0) {
                //myCoconut5->framecounterold = myCoconut5->framecounter;
            }
            count=3;
            /// bleibt hier und hält das Spiel an, solange info oder pause gedrückt sind
            //myCoconut5->framecounter = myCoconut5->framecounterold;
            //myPlayer->timePerFrame = sf::seconds(0.f/0.f);
            
        } 
        else {
            /// hier steht der normale Programmcode. Dieser wird unterbrochen und das Spiel angehalten, sofern pause oder info gedrückt ist
            //std::cout <<"Durchlauf" << std::endl;
            this->update();
            this->resetClock();
            this->checkCollision();
            //myCoconut5->framecounterold = myCoconut5->framecounter;
            count=0;
            gamebreak=false;
            //myPlayer->timePerFrame = sf::seconds(1.f/5.f);
            
        }
        this->render();
    }
}


/**
 * @brief this function checks player and the other objects for collision
 * 
 */
void Gui::checkCollision(){
    if ( Collision::PixelPerfectTest(myPlayer->sprite, myTiger->sprite ) &&
    (!Collision::PixelPerfectTest(myPlayer->sprite, spriteHome )) )
    {
        std::cout << "Collision Tiger!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()-5);
        myPlayer->sprite.setPosition(STARTPOSX, STARTPOSY);
        //delete(myPlayer);
    }else if ((Collision::PixelPerfectTest(myPlayer->sprite, myScorpion->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myScorpion2->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myScorpion3->sprite )) &&
                (!Collision::PixelPerfectTest(myPlayer->sprite, spriteHome )))
    {
        std::cout << "Collision Scorpion!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()-1);
        myPlayer->sprite.setPosition(STARTPOSX, STARTPOSY);
    }else if ((Collision::PixelPerfectTest(myPlayer->sprite, myCoconut->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myCoconut2->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myCoconut3->sprite ) ||
                Collision::PixelPerfectTest(myPlayer->sprite, myCoconut4->sprite )) &&
                (!Collision::PixelPerfectTest(myPlayer->sprite, spriteHome )))
    {
        std::cout << "Collision Coconut!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()-1);
        myPlayer->sprite.setPosition(STARTPOSX, STARTPOSY);
    }else if ((Collision::PixelPerfectTest(myPlayer->sprite, myCoconut5->sprite )) &&
    (!Collision::PixelPerfectTest(myPlayer->sprite, spriteHome )))
    {
        std::cout << "Collision Red Coconut!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()-3);
        myPlayer->sprite.setPosition(STARTPOSX, STARTPOSY);
    }else if (Collision::PixelPerfectTest(myPlayer->sprite, myHeart->sprite ))
    {
        std::cout << "Collision Heard!" << std::endl;
        myPlayer->set_Lives(myPlayer->get_Lives()+1);
        this->myHeart->sprite.setPosition(sf::Vector2f(this->myHeart->setRandomPosX(), this->myHeart->setRandomPosY()));
        //delete(myHeart);
    }else if (Collision::PixelPerfectTest(myPlayer->sprite, myBanana->sprite ))
    {
        std::cout << "Collision Banana!" << std::endl;
        myPlayer->addBanana();
        std::cout << myPlayer->getBanana() << std::endl;
        this->myBanana->sprite.setPosition(sf::Vector2f(this->myBanana->setRandomPosX(), this->myBanana->setRandomPosY()));
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
        myPlayer->checkWon();
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

    this->window->draw(myMenu->menuImage);
    this->window->draw(myMenu->heartImage);
    this->window->draw(myMenu->playButtonImage);
    this->window->draw(myMenu->infoButtonImage);
    this->window->draw(myMenu->bananaText);
    this->window->draw(myMenu->amountBananaText);
    this->window->draw(myMenu->livesText);
    this->window->draw(myMenu->amountlivesText);
    this->window->draw(myMenu->wonGamesText);
    this->window->draw(myMenu->amountwonGamesText);
    this->window->draw(myMenu->bananaImage);
    this->window->draw(myMenu->infowindowImage);
    this->window->draw(myMenu->infoText);

    this->window->display();
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
 * @brief opens and reads txt-file "manpage"
 * 
 */
void Gui::openManpage()
{   
    
    std::ifstream manpage;
    std::string gelesen;

    manpage.open("files\\manpage.txt");
    if (!manpage.fail())
    {
        while (std::getline(manpage, gelesen))
        {
            std::cout << gelesen << std::endl;
        }
    }else
    {
        std::cout << "Could not load manpage!" << std::endl;
    }
    
    manpage.close();

}// end openManpage
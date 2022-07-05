#pragma once
#include <SFML/Graphics.hpp>
#include "Heart.h"
#include "Banana.h"
#include "Coconut.h"
#include "Tiger.h"
#include "Scorpion.h"
#include "Tree.h"
#include "Player.h"
#include "Collision.h"

class Gui
{
private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;
    sf::Image icon;

    // create Label
    std::string txt_line;
    sf::Font font_comic;
    sf::Text txt_manpage;

    // create Ape (Player)
    Player *myPlayer = new Player(70.f, 300.f);

    // create Tiger (Endboss)
    Tiger *myTiger = new Tiger(300.f, 200.f);

    // create Scorpion
    Scorpion *myScorpion = new Scorpion(300.f, 100.f);
    Scorpion *myScorpion2 = new Scorpion(80.f, 80.f);
    Scorpion *myScorpion3= new Scorpion(150.f, 200.f);

    // create Heart
    Heart *myHeart = new Heart(100.f, 200.f);


    // create Coconut
    Coconut *myCoconut = new Coconut(-200.f,80.f, 1);
    Coconut *myCoconut2 = new Coconut(-500.f,200.f, 1);
    Coconut *myCoconut3 = new Coconut(-800.f,270.f, 1);
    Coconut *myCoconut4 = new Coconut(-1000.f,320.f, 1);
    Coconut *myCoconut5 = new Coconut(-1200.f,50.f, 0);

    // create Bananatree
    Tree *myTree = new Tree(100.f, 200.f);
    Tree *myTree2 = new Tree(150.f, 150.f);
    Tree *myTree3 = new Tree(200.f, 230.f);

    // create Banana
    Banana *myBanana = new Banana(200.f, 250.f);
    Banana *myBanana2 = new Banana(80.f, 100.f);
    Banana *myBanana3 = new Banana(400.f, 300.f);

    // create Home
    sf::Image imageHome;
    sf::Texture textureHome;
    sf::RectangleShape shapeHome;

    // create Jungle
    sf::Image imageJungle;
    sf::Texture textureJungle;
    sf::RectangleShape shapeJungle;

    void initVariables();
    void initWindow();
    
public:
    Gui();
    const bool running();
    void update();
    void render();
    void pollEvents();
    void checkWindow();
    void info_button();
    void start_button();
    void stop_button();
    void reset_button();
    void moveObjects();
    void resetClock();
    void checkObjBorder(Item *object);
    void checkMyBorders();
    // create Gamethings
    void createHome();
    void createJungle();

    // Manpage
    void openManpage();

    ~Gui();

    //changes for collision method
    void proofe_collision();
};
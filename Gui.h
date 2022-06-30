#pragma once
#include <SFML/Graphics.hpp>
#include "Heart.h"
#include "Banana.h"
#include "Coconut.h"
#include "Tiger.h"
#include "Scorpion.h"
#include "Tree.h"
#include "Player.h"

class Gui
{
private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    // create Label
    std::string txt_line;
    sf::Font font_comic;
    sf::Text txt_manpage;

/*    // create Ape (Player)
    sf::Image imageApe;
    sf::Texture textureApe;
    sf::RectangleShape shapeApe;
    sf::Sprite spriteApe;*/
    Player *myPlayer = new Player(70.f, 300.f);

/*    // create Tiger (Endboss)
    sf::Image imageTiger;
    sf::Texture textureTiger;
    sf::RectangleShape shapeTiger;
    sf::Sprite spriteTiger;*/
    Tiger *myTiger = new Tiger(300.f, 200.f);

    // create Scorpion
    Scorpion *myScorpion = new Scorpion(300.f, 100.f);

/*    // create Heart
    sf::Image imageHeart;
    sf::Texture textureHeart;
    sf::RectangleShape shapeHeart;
    sf::Sprite spriteHeart;*/
    Heart *myHeart = new Heart(100.f, 200.f);


/*    // create Coconut
    sf::Image imageCoconut;
    sf::Texture textureCoconut;
    sf::RectangleShape shapeCoconut;
    sf::Sprite spriteCoconut;*/
    Coconut *myCoconut = new Coconut(-200.f,80.f, 1);
    Coconut *myCoconut2 = new Coconut(-500.f,200.f, 1);
    Coconut *myCoconut3 = new Coconut(-800.f,270.f, 1);
    Coconut *myCoconut4 = new Coconut(-1000.f,320.f, 1);
    Coconut *myCoconut5 = new Coconut(-1200.f,50.f, 0);
/*    // create Bananatree
    sf::Image imageBananatree;
    sf::Texture textureBananatree;
    sf::RectangleShape shapeBananatree;
    sf::Sprite spriteBananatree;*/
    Tree *myTree = new Tree(100.f, 200.f);
/*
    // create Banana
    sf::Image imageBanana;
    sf::Texture textureBanana;
    sf::RectangleShape shapeBanana;
    sf::Sprite spriteBanana;*/
    Banana *myBanana = new Banana(200.f, 250.f);

    // create Home
    sf::Image imageHome;
    sf::Texture textureHome;
    sf::RectangleShape shapeHome;
    sf::Sprite spriteHome;

    // create Jungle
    sf::Image imageJungle;
    sf::Texture textureJungle;
    sf::RectangleShape shapeJungle;
    sf::Sprite spriteJungle;

    void initVariables();
    void initWindow();
    
    int guiCounter = 0;
public:
    Gui();
    const bool running();
    void update();
    void render();
    void pollEvents();
    void checkWindow();
    void setField(int *field[]);
    void info_button();
    void start_button();
    void stop_button();
    void reset_button();
    void allCoconutsFly();
    void resetCocoClock();
    // create Gamethings
    //void createApe();
    //void createTiger();
    //void createHeart();
    //void createCoconut();
    //void createBananatree();
    //void createBanana();
    void createHome();
    void createJungle();

    // Manpage
    void openManpage();

    ~Gui();
};
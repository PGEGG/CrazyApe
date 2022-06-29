#pragma once
#include <SFML/Graphics.hpp>
#include "Heart.h"
#include "Banana.h"
#include "Coconut.h"

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

    // create Ape (Player)
    sf::Image imageApe;
    sf::Texture textureApe;
    sf::RectangleShape shapeApe;
    sf::Sprite spriteApe;

    // create Tiger (Endboss)
    sf::Image imageTiger;
    sf::Texture textureTiger;
    sf::RectangleShape shapeTiger;
    sf::Sprite spriteTiger;

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
    Coconut *myCoconut = new Coconut(200);

    // create Bananatree
    sf::Image imageBananatree;
    sf::Texture textureBananatree;
    sf::RectangleShape shapeBananatree;
    sf::Sprite spriteBananatree;
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

    // create Gamethings
    void createApe();
    void createTiger();
    //void createHeart();
    //void createCoconut();
    void createBananatree();
    //void createBanana();
    void createHome();
    void createJungle();

    // Manpage
    void openManpage();

    ~Gui();
};
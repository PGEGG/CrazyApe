#ifndef Gui_h
#define Gui_h
#include <SFML/Graphics.hpp>


class Gui
{
private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

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

    // create Heart
    sf::Image imageHeart;
    sf::Texture textureHeart;
    sf::RectangleShape shapeHeart;
    sf::Sprite spriteHeart;

    // create Coconut
    sf::Image imageCoconut;
    sf::Texture textureCoconut;
    sf::RectangleShape shapeCoconut;
    sf::Sprite spriteCoconut;

    // create Bananatree
    sf::Image imageBananatree;
    sf::Texture textureBananatree;
    sf::RectangleShape shapeBananatree;
    sf::Sprite spriteBananatree;

    // create Banana
    sf::Image imageBanana;
    sf::Texture textureBanana;
    sf::RectangleShape shapeBanana;
    sf::Sprite spriteBanana;

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

    //create Gamethings
    void createApe();
    void createTiger();
    void createHeart();
    void createCoconut();
    void createBananatree();
    void createBanana();
    void createHome();
    void createJungle();

    ~Gui();
};

#endif
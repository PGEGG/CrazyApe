#ifndef Gui_h
#define Gui_h
#include <SFML/Graphics.hpp>


class Gui
{
private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;
    sf::Image image;
    sf::Texture texture;
    sf::RectangleShape shape;
    sf::Sprite sprite;

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
    ~Gui();
};

#endif
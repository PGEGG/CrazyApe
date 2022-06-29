#ifndef Player_h
#define Player_h
#include <SFML/Graphics.hpp>

class Player
{
private:
    int lives=5;
    float pos_x = 0;
    float pos_y = 0;
    int collected_banana=0;

    // create Player
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;


public:
    Player();
    Player(float x, float y);
    ~Player();

    void increase_banana();
    bool move_detected();
    bool move_check();
    void move();
    void change_lives(int value);
    void check_new_cmd();
    int get_Banana();
    int get_Lives();
    
    sf::RectangleShape playerShape;
    float playerWidth = 50.f;
    float playerHeight = 80.f;
        
};

#endif
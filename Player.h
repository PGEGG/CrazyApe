#ifndef Player_h
#define Player_h

class Player
{
private:
    int lives=5;
    int pos_x=0;
    int pos_y=0;
    int collected_banana=0;

public:
    Player();
    ~Player();

    void increase_banana();
    bool move_detected();
    bool move_check();
    void move();
    void change_lives(int value);
    void check_new_cmd();
    int get_Banana();
    int get_Lives();
    
        
};

#endif
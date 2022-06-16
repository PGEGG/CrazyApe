#include "Player.h"
#include <iostream>


using namespace std;

Player::Player()
{
    pos_x = 5;
    pos_y = 5;

}

Player::~Player()
{

}

void Player::increase_banana()
{
    
}

bool Player::move_detected(){
    return false;
}

bool Player::move_check()
{
    return false;
}

void Player::move()
{

}

void Player::change_lives(int value)
{

}

void Player::check_new_cmd()
{

}

int Player::get_Banana()
{
    return collected_banana;
}

int Player::get_Lives()
{
    return lives;
}
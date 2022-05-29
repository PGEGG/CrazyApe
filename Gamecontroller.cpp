#include "Gamecontroller.h"
#include "Player.h"
#include "Item.h"
#include "Banana.h"
#include "Heart.h"
#include "Gui.h"
#include "Animal.h"
#include "Tiger.h"
#include "Scorpion.h"

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

Gamecontroller::Gamecontroller()
{
}

Gamecontroller::~Gamecontroller()
{

}

void Gamecontroller::startGame(){
    int field=getfield();
    // Create Object Player
    Player myPlayer;

    //Create Object Gui
    Gui myGui;

    // Create bananas
    Banana myBanana1((field/100),(field%100));  //later--> random number and proofe if field free
    field=getfield();
    Banana myBanana2(8,8);
    Banana myBanana3(9,9);

    //create Object Heart
    Heart myHeart(10,10);

    //Create Object Tiger
    Tiger myTiger;      //Sporns in Forest

    //create scorpions
    Scorpion myScorpion1(3,3);
    Scorpion myScorpion2(4,4);
    Scorpion myScorpion3(5,5);


}

bool Gamecontroller::checkWon(){

}

void Gamecontroller::reset(){

}
bool Gamecontroller::freePosition(int x, int y){
    
    

}

int Gamecontroller::randomNumber(int size){
    /* initialize random seed: */
     srand (time(NULL));

    /* generate secret number between 1 and 10: */
    return (rand() % size + 1);

}
int Gamecontroller::getfield(){
    int x = 0, y = 0;
    do{
        x =randomNumber(50);
        y= randomNumber(40);
        //überprüfen feld fei?
        bool fieldfree=false;
    } while (false);
    x *= 100;
    return(x + y);
    
}
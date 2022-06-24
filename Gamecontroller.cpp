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
    // Create Object Player
    Player *myPlayer = new Player;
    //Create Object Gui
    Gui myGui;
    
    /*
    while (myGui.running())
    {
        myGui.update();
        myGui.render();
    }
    */
    myGui.checkWindow();

    // Create bananas
    int position=getfield();
    Banana *myBanana1 = new Banana((position/100),(position%100));
    position=getfield();
    Banana *myBanana2 = new Banana((position/100),(position%100));
    position=getfield();
    Banana *myBanana3 = new Banana((position/100),(position%100));

    //create Object Heart
    position=getfield();
    Heart *myHeart = new Heart((position/100),(position%100));

    //Create Object Tiger
    Tiger *myTiger = new Tiger;      //Sporns in Forest

    //create scorpions
    position=getfield();
    Scorpion *myScorpion1 = new Scorpion((position/100),(position%100));
    position=getfield();
    Scorpion *myScorpion2 = new Scorpion((position/100),(position%100));
    position=getfield();
    Scorpion *myScorpion3 = new Scorpion((position/100),(position%100));


}

bool Gamecontroller::checkWon(){
    /*
    if(myPlayer->get_banana==3) {

        return true;
    }
    */
    return false;
}

bool Gamecontroller::checkDeath(){
    /*
    if (myPlayer->get_Lives==0) {
        return true;
    }
    //or proofe if he touch the tiger
    */
    return false;
}

// method is called if the game is finished
void Gamecontroller::reset(){
    //reset gamefield
    for (int i=0;i<50;i++) {
        for (int j=0;j<40;j++) {
            field[i][j] = 0;
        }
    }
    //delete player and create a new one or reset all variables (lives, banana...)
    //same for Animals and Items to change their position
    //create bananas
}
// check if Gamefield is free
bool Gamecontroller::freePosition(int x, int y){
    if(field[x][y]==0) {
        return true;
    }
    return false;
}

// get a random number
int Gamecontroller::randomNumber(int size){
    /* initialize random seed: */
     srand (time(NULL));

    /* generate secret number between 1 and 10: */
    return (rand() % size + 1);
}

//get an empty gamefield
int Gamecontroller::getfield(){
    int x = 0, y = 0;
    do{
        x = randomNumber(50);
        y = randomNumber(40);
        //proofe if field free? (if field =0)
    } while (!freePosition(x,y));

    printf("X: %d\n",x);
    printf("Y: %d\n",y);

    
    x *= 100;
    //bsp.: 5040 for x=50;y=40
    
    return (x+y);
    
}
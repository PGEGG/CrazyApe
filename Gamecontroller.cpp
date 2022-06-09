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
    Player myPlayer;

    //Create Object Gui
    Gui myGui;

    // Create bananas
    int position=getfield();
    Banana myBanana1((position/100),(position%100));  
    position=getfield();
    Banana myBanana2((position/100),(position%100));
    position=getfield();
    Banana myBanana3((position/100),(position%100));

    //create Object Heart
    position=getfield();
    Heart myHeart((position/100),(position%100));

    //Create Object Tiger
    Tiger myTiger;      //Sporns in Forest

    //create scorpions
    position=getfield();
    Scorpion myScorpion1((position/100),(position%100));
    position=getfield();
    Scorpion myScorpion2((position/100),(position%100));
    position=getfield();
    Scorpion myScorpion3((position/100),(position%100));


}

bool Gamecontroller::checkWon(){
    return false;
}

void Gamecontroller::reset(){
    for (int i=0;i<50;i++) {
        for (int j=0;j<40;j++) {
            field[i][j] = 0;
        }
    }
}
bool Gamecontroller::freePosition(int x, int y){
    
    return false;
    

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
        x = randomNumber(50);
        y = randomNumber(40);
        //überprüfen feld fei?
    } while (field[x][y]!=0);

    printf("X: %d\n",x);
    printf("Y: %d\n",y);

    
    x *= 100;
    //bsp.: 5040 for x=50;y=40
    
    return (x+y);
    
}
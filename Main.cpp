/*##########################################################################################################
####                           @Birk Henrik, @Eckerle Jan, @Gegg Patrick                                ####
####                                Crazy Ape:  Summer Semester 2022                                    ####
##########################################################################################################*/
#include "Main.h"
#include <iostream>
#include "Gamecontroller.h"
#include "Coconut.h"
#include "Gui.h"
#include "Heart.h"
#include "Item.h"
#include "Player.h"
#include "Scorpion.h"
#include "Tiger.h"

using namespace std;

int main(int argc, char* argv[]){

    cout << "Starting CrazyApe ...\n" << endl;

    // Create an dynamic Object "on HEAP" fram Gamecontroller
    Gamecontroller *myGc = new Gamecontroller;
    myGc->startGame();

    delete(myGc);

    return 0;

}//end main
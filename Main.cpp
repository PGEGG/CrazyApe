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

int main(int argc, char* argv[]){

    printf("CrazyApe\n");

    // Create an Object fram Gamecontroller
    Gamecontroller myGc;
    myGc.startGame();

    return 0;

}//end main
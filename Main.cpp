/*##########################################################################################################
####                           @Birk Henrik, @Eckerle Jan, @Gegg Patrick                                ####
####                                Crazy Ape:  Summer Semester 2022                                    ####
##########################################################################################################*/
#include "Main.h"

int main(int argc, char* argv[]){

    std::cout << "Starting CrazyApe ...\n" << std::endl;

    //closing the CMD window
    FreeConsole();

    // Create an dynamic Object "on HEAP" fram Gamecontroller
    Gamecontroller *myGc = new Gamecontroller;
    myGc->startGame();

    delete(myGc);

    return EXIT_SUCCESS;

}//end main
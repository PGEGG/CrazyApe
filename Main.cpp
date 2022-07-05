/*##########################################################################################################
####                           @Birk Henrik, @Eckerle Jan, @Gegg Patrick                                ####
####                                Crazy Ape:  Summer Semester 2022                                    ####
##########################################################################################################*/
#include "Main.h"

int main(int argc, char* argv[]){

    std::cout << "Starting CrazyApe ...\n" << std::endl;

    /// closing the CMD window
    /// FreeConsole();

    /**
     * @brief Create an dynamic Object "on HEAP" from Gamecontroller
     * 
     */
    Gamecontroller *myGc = new Gamecontroller;
    myGc->startGame();  /// start the Game in Gamecontroller

    /**
     * @brief delete Gamecontroller Object
     * 
     */
    delete(myGc);

    return EXIT_SUCCESS;

}//end main
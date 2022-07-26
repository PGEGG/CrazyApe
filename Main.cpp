/*##########################################################################################################
####                           @Birk Henrik, @Eckerle Jan, @Gegg Patrick                                ####
####                                 Crazy Ape:  2-Semester 2022                                        ####
##########################################################################################################*/
#include "Main.h"

int main(int argc, char* argv[]){

    std::cout << "Starting CrazyApe.exe ..." << std::endl;

    /// closing the CMD window
    FreeConsole();

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

    std::cout << "Ending CrazyApe.exe ..." << std::endl;

    return EXIT_SUCCESS;

}//end main
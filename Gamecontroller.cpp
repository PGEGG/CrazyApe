#include "Gamecontroller.h"

/**
 * @brief Construct a new Gamecontroller:: Gamecontroller object
 * default Constructor
 */
Gamecontroller::Gamecontroller()
{

}
/**
 * @brief Destroy the Gamecontroller:: Gamecontroller object
 * 
 */
Gamecontroller::~Gamecontroller()
{

}
/**
 * @brief start the Game
 *  intialise the music
 * create Object of Gui
 * call checkWindow()
 */
void Gamecontroller::startGame(){
    /**
     * @brief initialise the music
     * 
     */
    sf::Music music;

    /// if it couldn`t load the music
    if (!(music.openFromFile("music//music.ogg"))){
        std::cout << "Failed to load music" << std::endl;
    }
    music.play();
    music.setLoop(true);


    /**
     * @brief create Object of Gui
     * 
     */
    Gui *myGui = new Gui;
    
    ///call checkWindow() to initialise Jungle, Home an Manpage
    myGui->checkWindow();

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

// get a random number
int Gamecontroller::randomNumber(int size){
    /* initialize random seed: */
     srand (time(NULL));

    /* generate secret number between 1 and 10: */
    return (rand() % size + 1);
}
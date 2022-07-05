#include "Gamecontroller.h"


Gamecontroller::Gamecontroller()
{
}

Gamecontroller::~Gamecontroller()
{

}

void Gamecontroller::startGame(){
    //Play music
    sf::Music music;
    if (!(music.openFromFile("music//music.ogg"))){
        std::cout << "Failed to load music" << std::endl;
    } // error
    music.play();
    music.setLoop(true);

    // Create Object Player
    Player *myPlayer = new Player;
    //Create Object Gui
    Gui *myGui = new Gui;
    
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
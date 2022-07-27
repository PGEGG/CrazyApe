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

    /// load the music file
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
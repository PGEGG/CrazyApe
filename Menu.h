#ifndef Menu_h
#define Menu_h
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Player.h"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::to_string;
using std::cerr;
using std::ifstream; using std::ostringstream;

class Menu {
    private:

        bool info = false;
        bool pause = false;
        int amountBanana = 0;
        int amountlives = 3;
        int amountwongames =0;
        string strbanana = "";
        string strlives = "";
        string strwon = "";


        void setPauseButton();
        void setPlayButton();
        void setInfoButton();
        void initialiseMenu();
        string readFileIntoString(const string& path);
        
    
    public:
        sf::Texture infoButton;
        sf::Sprite infoButtonImage;

        /// Play-Pause Button
        sf::Texture playButton;
        sf::Sprite playButtonImage;

         /// set menubar
        sf::Texture menu;
        sf::Sprite menuImage;

        sf::Text infoText;

        /// set Heart picture
        sf::Texture heart;
        sf::Sprite heartImage;

        /// set Banana picture
        sf::Texture banana;
        sf::Sprite bananaImage;

        /// set infowindow
        sf::Texture infowindow;
        sf::Sprite infowindowImage;

        sf::Text bananaText;

        sf::Text amountBananaText;

        sf::Text livesText;

        sf::Font font;

        sf::Text amountlivesText;

        sf::Text wonGamesText;

        sf::Text amountwonGamesText;

        Menu();
        ~Menu();
        void checkInfoButton();
        bool getInfo();
        bool getPause();
        void pauseclicked();
        void infoclicked();
        void updateBananaHeart(Player* myPlayer);

};
#endif
#include "Menu.h"

Menu::Menu() {
    this->initialiseMenu();
}

Menu::~Menu() {
    
}

void Menu::setPauseButton() {
  if (!playButton.loadFromFile("images//PAUSE.png")) {
    std::cout << "Can't find the image" << std::endl;
  }
  playButtonImage.setScale(sf::Vector2f(0.4f, 0.4f));
  playButtonImage.setPosition(10.0f, 4.0f);
  //float playButtonWidth = playButtonImage.getLocalBounds().width;
  //float playButtonHeight = playButtonImage.getLocalBounds().height;
  playButtonImage.setTexture(playButton);
}

void Menu::setPlayButton() {
  if (!playButton.loadFromFile("images//PLAY.png")) {
    std::cout << "Can't find the image" << std::endl;
  }
}

void  Menu::setInfoButton() {
  if (!infoButton.loadFromFile("images//INFO.png")) {
    std::cout << "Can't find the image" << std::endl;
  }
  infoButtonImage.setScale(sf::Vector2f(0.5f, 0.5f));
  infoButtonImage.setPosition(850.0f, 12.0f);
  //float infoButtonWidth = infoButtonImage.getLocalBounds().width;
  //float infoButtonHeight = infoButtonImage.getLocalBounds().height;
  infoButtonImage.setTexture(infoButton);
}

void  Menu::pauseclicked() {
  std::cout << "play/pause clicked!\n";
  if (!pause)
  {
    pause = true;
    setPlayButton();
  }
  else if (pause)
  {
    pause = false;
    setPauseButton();
    
    // if play was clicked and info is open
    if (info) {
      /// remove the info window if play was clicked
      infowindowImage.setScale(sf::Vector2f(0.0f, 0.0f)); 
      ///remove the info text
      infoText.setString("");
      info=false;
      //change the icon of info-Button
      setInfoButton();
    }
  }
  pause!=pause;
}

void  Menu::infoclicked() {
  std::cout << "info clicked!\n";
  if (!info)
  {

    if (!infoButton.loadFromFile("images//CLOSE_INFO.png")) {
      std::cout << "Can't find the image" << std::endl;
    }
    infoButtonImage.setPosition(850.0f, 12.0f);
    infoButtonImage.setTexture(infoButton);

    /// set pause if info is opened and do not restart the gae automatically if info is closed --> have to press play to restart the game
    if (!pause) {
      pause = true;
      setPlayButton();
    }
  }
  else if (info)
  {
    setInfoButton();
  }
  info=!info;
}

/*
void  Menu::checkButtonEvents(sf::RenderWindow *window) {
  sf::Event Event;
  while (window->pollEvent(Event))
  {
    /// call up event
    switch (Event.type)
    {
    /// if window is closed  
    case sf::Event::Closed:
      window->close();
      break;
    
    /// mouse button is ckicked
    case sf::Event::MouseButtonPressed:
    {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

      /// if button play/pause button is clicked
      if (playButtonImage.getGlobalBounds().contains(mousePosF))
      {
        pauseclicked();
      }

      /// if button info is clicked
      if (infoButtonImage.getGlobalBounds().contains(mousePosF))
      {
        infoclicked();
      }
    }      
    break;
    }
  }
}
*/
void  Menu::initialiseMenu() {
    /*
  /// background
  if (!background.loadFromFile("images//jungle.png")) {
    std::cout << "Error: Could not load image" << std::endl;
  }
  backgroundImage.setTexture(background);
*/
  /// menubar (at the top)
  if (!menu.loadFromFile("images//menubar.png")) {
    std::cout << "Error: Could not display image" << std::endl;
  }
  menuImage.setPosition(0.0f, 0.0f);
  menuImage.setScale(sf::Vector2f(1.5f, 0.65f));
  menuImage.setTexture(menu);

  ///info window (white background)
  if (!infowindow.loadFromFile("images//infowindow.png")) {
    std::cout << "Error: Could not display image" << std::endl;
  }
  infowindowImage.setPosition(45.0f, 60.0f);
  infowindowImage.setScale(sf::Vector2f(0.0f, 0.0f));
  infowindowImage.setTexture(infowindow);

  /// text style
  if ( !font.loadFromFile( "files\\MATURASC.TTF" )) {
    std::cout << "Can't find the font file" << std::endl;
  }

  /// play/pause Button
  setPauseButton();

  /// Info Button
  setInfoButton();

  /// banana icon
  if (!banana.loadFromFile("images//banana.png")) {
    std::cout << "Error: Could not load image" << std::endl;
  }
  bananaImage.setPosition(250.0f, 10.0f);
  bananaImage.setScale(sf::Vector2f(0.15f, 0.15f));
  bananaImage.setTexture(banana);

  /// BananaText
  bananaText.setFont( font );
  bananaText.setStyle(sf::Text::Bold);
  bananaText.setString("Banana: ");
  bananaText.setFillColor(sf::Color::Black);
  bananaText.setCharacterSize(30);
  bananaText.setPosition(100.0f, 0.0f);
  
  ///amountBanana
  amountBananaText.setFont( font );
  amountBananaText.setStyle(sf::Text::Bold);
  strbanana += to_string(amountBanana);
  amountBananaText.setString(strbanana);
  amountBananaText.setFillColor(sf::Color::Black);
  amountBananaText.setCharacterSize(30);
  amountBananaText.setPosition(230.0f, 0.0f);

  /// heart icon
  if (!heart.loadFromFile("images//heart.png")) {
    std::cout << "Error: Could not load image" << std::endl;
  }
  heartImage.setPosition(480.0f, 10.0f);
  heartImage.setScale(sf::Vector2f(0.15f, 0.15f));
  heartImage.setTexture(heart);
  
  /// Lives Text
  livesText.setFont( font );
  livesText.setStyle(sf::Text::Bold);
  livesText.setString("Lives: ");
  livesText.setFillColor(sf::Color::Black);
  livesText.setCharacterSize(30);
  livesText.setPosition(350.0f, 0.0f);
  
  /// amount Lives
  amountlivesText.setFont( font );
  amountlivesText.setStyle(sf::Text::Bold);
  strlives += to_string(amountlives);
  amountlivesText.setString(strlives);
  amountlivesText.setFillColor(sf::Color::Black);
  amountlivesText.setCharacterSize(30);
  amountlivesText.setPosition(460.0f, 0.0f);
  
  /// WonGames Text
  wonGamesText.setFont( font );
  wonGamesText.setStyle(sf::Text::Bold);
  wonGamesText.setString("Won Games:");
  wonGamesText.setFillColor(sf::Color::Black);
  wonGamesText.setCharacterSize(30);
  wonGamesText.setPosition(600.0f, 0.0f);
  
  /// amount WonGames
  amountwonGamesText.setFont( font );
  amountwonGamesText.setStyle(sf::Text::Bold);
  strwon += to_string(amountwongames);
  amountwonGamesText.setString(strwon);
  amountwonGamesText.setFillColor(sf::Color::Black);
  amountwonGamesText.setCharacterSize(30);
  amountwonGamesText.setPosition(795.0f, 0.0f);
}

string Menu::readFileIntoString(const string& path) {
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        exit(EXIT_FAILURE);
    }
    return string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

void  Menu::checkInfoButton() {
  /// if info menu
  if (info) {
    /// make info visible
    infowindowImage.setScale(sf::Vector2f(0.74f, 0.65f));

    infoText.setFont( font );
    infoText.setStyle(sf::Text::Bold);
    infoText.setString(readFileIntoString("files\\manpage.txt"));
    infoText.setFillColor(sf::Color::Black);
    infoText.setCharacterSize(27);
    infoText.setPosition(80.0f, 90.0f);
  } 
  else {    
    infowindowImage.setScale(sf::Vector2f(0.0f, 0.0f)); 
    infoText.setString("");
  }
}

void Menu::updateBananaHeart(Player* myPlayer) {
    strbanana = to_string(myPlayer->getBanana());
    amountBananaText.setString(strbanana);

    strlives = to_string(myPlayer->get_Lives());
    amountlivesText.setString(strlives);
}

bool Menu::getPause() {
    return pause;
}

bool Menu::getInfo() {
    return info;
}


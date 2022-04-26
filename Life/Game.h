#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include "SFML/Graphics.hpp"
#include "Field.h"
#include "Menu.h"

class Game{
public:
    Game();
    ~Game();
private:
    void stopGameOfClickingOnSpace();
    void processing();

    sf::RenderWindow* mWindow;
    sf::Event* mEvent;
    bool* mIsStop;
    bool* mIsMenuOpen;
    Field* mField;
    Menu* mMenu;
};

#endif //LIFE_GAME_H

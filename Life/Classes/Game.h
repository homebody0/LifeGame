#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include "SFML/Graphics.hpp"
#include "Field.h"
#include "Menu.h"
#include "Inventory.h"

class Game{
public:
    Game();
    ~Game();
private:
    void stopGameOfClickingOnSpace();
    void processing();
    void moveView();
    void scaleView();

    sf::RenderWindow* mWindow;
    sf::View* mCamera;
    sf::Vector2f* mPreviousViewPosition;

    sf::Event* mEvent;

    bool* mIsStop;
    bool* mIsMenuOpen;
    bool* mIsInventoryOpen;

    Field* mField;
    Menu* mMenu;
    Inventory* mInventory;
};

#endif //LIFE_GAME_H

#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include "SFML/Graphics.hpp"
#include "Field.h"

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
    Field* mField;
};

#endif //LIFE_GAME_H

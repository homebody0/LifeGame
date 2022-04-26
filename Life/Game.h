#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include "Field.h"
#include "SFML/Graphics.hpp"

class Game{
public:
    Game(sf::Vector2u size);
    ~Game();
private:
    void draw();
    void processingEvents();
    sf::Vector2u whenMouse();
    bool* mIsStop;
    Field* mField;
    sf::Event* mEvent;
    sf::RenderWindow* mWindow;
};

#endif //LIFE_GAME_H

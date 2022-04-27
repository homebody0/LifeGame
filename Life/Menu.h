#ifndef LIFE_MENU_H
#define LIFE_MENU_H

#include "SFML/Graphics.hpp"
#include "vector"
#include "Button.h"

class Menu: public sf::Drawable{
public:
    Menu(sf::Vector2u sizeWindow);
    static void openMenu(sf::Event event, bool* isMenuOpen, bool* isStop);
    ~Menu() override;
private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2f* mButtonsSize;
    std::vector<Button*>* mButtons;
};

#endif //LIFE_MENU_H

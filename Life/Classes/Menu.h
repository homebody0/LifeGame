#ifndef LIFE_MENU_H
#define LIFE_MENU_H

#include "SFML/Graphics.hpp"
#include "vector"
#include "Button.h"

class Menu: public sf::Drawable{
public:
    Menu(sf::Vector2f viewSize);
    void updateMenuDraw(sf::Vector2f viewPosition, sf::Vector2f viewSize);
    static void openMenu(sf::Event event, bool* isMenuOpen, bool* isStop);
    void usingMenu(sf::Vector2f mousePosition, bool *isClear, bool *isMenuOpen, bool *isInventoryOpen,
                   sf::RenderWindow *window);
    ~Menu() override;
private:
    enum whatButton{RESUME, FIGURES, CLEAR, EXIT};
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    std::vector<Button*>* mButtons;
};

#endif //LIFE_MENU_H
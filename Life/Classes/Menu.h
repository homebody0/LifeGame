#ifndef LIFE_MENU_H
#define LIFE_MENU_H

#include "SFML/Graphics.hpp"
#include "vector"
#include "Button.h"

class Menu: public sf::Drawable{
public:
    Menu(sf::Vector2f viewSize); //объявление переменных
    void updateMenuDraw(sf::Vector2f viewPosition, sf::Vector2f viewSize); //обновление позиций и размеров всего меню
    static void openMenu(sf::Event event, bool* isMenuOpen, bool* isStop); //открытие меню через нажатие на ESC
    void usingMenu(sf::Vector2f mousePosition, bool *isClear, bool *isMenuOpen, bool *isInventoryOpen, //взаимодействие с меню
                   sf::RenderWindow *window);
    ~Menu() override; //удаление переменных
private:
    enum whatButton{RESUME, FIGURES, CLEAR, EXIT}; //номера кнопок
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //отрисовка меню
    std::vector<Button*>* mButtons; //динамический массив кнопок
};

#endif //LIFE_MENU_H

#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include "SFML/Graphics.hpp"
#include "Field.h"
#include "Menu.h"
#include "Inventory.h"

class Game{
public:
    Game(); //объявление переменных и запуск игры
    ~Game(); //удаление пременных
private:
    void stopGameOfClickingOnSpace(); //пауза/пуск игры нажатием пробела
    void processing(); //обработка событий и отрисовка
    void moveView(); //движение камеры
    void scaleView(); //масштабирование камеры
    void closeInfo(); //закрытие информационных окон

    sf::RenderWindow* mWindow; //окно
    sf::View* mCamera; //камеры
    sf::Vector2f* mPreviousViewPosition; //предыдущее положение мыши

    sf::Event* mEvent; //событие

    bool* mIsStop; //остановленна ли игра
    bool* mIsMenuOpen; //открыто ли меню
    bool* mIsInventoryOpen; //открыт ли инвентарь

    Field* mField; //поле
    Menu* mMenu; //меню
    Inventory* mInventory; //инвентарь

    bool *mIsFirstPlayGame;
    bool *mIsFirstOpenInventory;
    bool *mIsFirstPlayGameDisplayed;
    bool *mIsFirstOpenInventoryDisplayed;
    sf::Texture *mTextureGameControlInfo;
    sf::Texture *mTextureInventoryControlInfo;
    sf::Sprite *mGameControlInfo;
    sf::Sprite *mInventoryControlInfo;
};

#endif //LIFE_GAME_H

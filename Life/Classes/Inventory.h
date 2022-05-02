#ifndef LIFE_INVENTORY_H
#define LIFE_INVENTORY_H

#include "SFML/Graphics.hpp"
#include "vector"
#include "iostream"
#include "Figure.h"

class Inventory: public sf::Drawable{
public:
    Inventory(sf::Vector2f sizeWindow, int countOnHorizontal); //обяъвление переменных
    void addFigure(const std::string& imageFilename, const std::string& informationFilename); //добавление фигуры в инвентарь
    void scroll(sf::Event *event); //пролистывание инвентаря
    void updateInventoryDraw(sf::Vector2f viewPosition, sf::Vector2f viewSize); //обновление позиций и размеров всего инвентаря
    void dragDrop(sf::Event event, sf::Vector2f mousePosition, sf::Sprite *inputSprite, bool *isInput); //взаимодействие с фигурами
    static void openInventory(sf::Event event, bool *isInventoryOpen, bool *isStop); //открытие инвентаря нажатием на Е
    ~Inventory() override; //удаление переменных
private:
    void rotation(sf::Event event); //вращение фигур
    int getFigureAt(sf::Vector2f mousePosition); //получить номер фигуры от позиции мыши на экране
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override; //отрисовка инвентаря

    int* mCountOfX; //кол-во фигур в длину
    sf::Vector2f* mSizeOneFigure; //размер одной фигуры
    sf::RectangleShape* mBackground; //фон
    std::vector<Figure*>* mFigures; //динамический массив фигур
    std::vector<sf::RectangleShape*>* mVerticalLines; //динамический массив вертикальных линий
    std::vector<sf::RectangleShape*>* mHorizontalLines; //динамический массив горизонтальных линий

    float* mScrollDistance; //длина пролистывания инвентаря

    bool* mIsShowInformation; //показывается ли информация

    sf::Sprite* mDraggingSprite; //спрайт выбранной фигуры
    sf::Texture* mDraggingTexture; //текстура выбранной фигуры
    int* mClickFigureNumber; //номер выбранной фигуры
    bool* mIsDragging; //выбранна ли фигура
};

#endif //LIFE_INVENTORY_H

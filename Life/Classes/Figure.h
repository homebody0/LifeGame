#ifndef LIFE_FIGURE_H
#define LIFE_FIGURE_H

#include "SFML/Graphics.hpp"

class Figure: public sf::Drawable{
public:
    Figure(); //объявление переменных
    void setScale(float x, float y); //масштабирование фигуры
    void setPosition(float x, float y); //задаёт позицию фигуры
    sf::Sprite getSprite(); //получение срайта фигуры
    sf::Sprite *getInformation(); //получение указателя на спрайт информации о фигуре
    void updateInformationDrawing(sf::Vector2f viewPosition, sf::Vector2f viewSize); //обновление позиции и размера спрайта информации
    sf::Texture getTexture(); //получение текстуры фигуры
    void loadFromFile(const std::string& filenameFigure, const std::string& filenameInformation); //загрузка изображений в текстуры
    sf::FloatRect getGlobalBounds(); //получение размеров и положения фигуры с учётом масштабирвания
    ~Figure(); //удаление переменных
private:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override; //отрисовка объекта

    sf::Sprite* mSprite;
    sf::Sprite* mSpriteInformation;

    sf::Texture* mTexture;
    sf::Texture* mInformation;
};

#endif //LIFE_FIGURE_H

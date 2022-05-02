#ifndef LIFE_FIELD_H
#define LIFE_FIELD_H

#include <SFML/Graphics.hpp>

class Field : public sf::Drawable{
public:
    Field(sf::Vector2u sizeWindow); //объявление переменных и создание поля
    void updateCells(); //1 шаг(ход) игры
    void addingLifeCells(sf::Event event, sf::Vector2f mousePosition); //добавление/удаление живых клеток через нажатие мыши
    void inputFigure(const sf::Sprite& inputSprite); //вставление фигуры
    void clear(); //отчистка поля
    ~Field() override; //удаление переменных
private:
    unsigned int countCells(unsigned int x, unsigned int y); //возвращает кол-во живых клеток вокруг клетки координат (x,y)
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //отрисовка объекта
    sf::Vector2u mImageSize; //размер изображения
    sf::Image* mField; //изображение поля
    sf::Texture* mFieldTexture; //текстура поля
    sf::Sprite* mFieldSprite; //спрайт поля
};

#endif //LIFE_FIELD_H

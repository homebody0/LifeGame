#ifndef LIFE_BUTTON_H
#define LIFE_BUTTON_H

#include "SFML/Graphics.hpp"

class Button: public sf::Drawable{
public:
    Button(const std::string& filenameImage, sf::Vector2f size, sf::Vector2f position); //объявление переменных
    bool isClick(sf::Vector2f mousePosition); //проверка принодлежности курсора к кнопке
    void setSize(sf::Vector2f size); //задаёт размер
    void setPosition(sf::Vector2f position); //задаёт позицию
    ~Button() override; //удаление переменных
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; //отрисовка объекта
    sf::Texture* mTexture; // текстура кнопки
    sf::RectangleShape* mButton; // спрайт кнопки
};

#endif //LIFE_BUTTON_H

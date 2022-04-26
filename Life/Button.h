#ifndef LIFE_BUTTON_H
#define LIFE_BUTTON_H

#include "SFML/Graphics.hpp"

class Button: public sf::Drawable{
public:
    Button(const std::string& filenameImage, sf::Vector2f size, sf::Vector2f position);
    bool isClick(sf::Event event);
    ~Button() override;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Texture* mTexture;
    sf::RectangleShape* mButton;
};

#endif //LIFE_BUTTON_H

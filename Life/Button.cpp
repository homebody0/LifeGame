#include "Button.h"

Button::Button(const std::string& filenameImage, sf::Vector2f size, sf::Vector2f position) {
    mTexture = new sf::Texture;
    mTexture->loadFromFile(filenameImage);

    mButton = new sf::RectangleShape;
    mButton->setTexture(mTexture);
    mButton->setSize(size);
    mButton->setPosition(position);
}

bool Button::isClick(sf::Event event) {
    return (event.type == sf::Event::MouseButtonPressed
                &&
    ((float)event.mouseButton.x >= mButton->getPosition().x && (float)event.mouseButton.x <= mButton->getPosition().x + mButton->getSize().x
                &&
    (float)event.mouseButton.y >= mButton->getPosition().y && (float)event.mouseButton.y <= mButton->getPosition().y + mButton->getSize().y));
}

Button::~Button() {
    delete mButton;
    delete mTexture;
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*mButton);
}

void Button::setSize(sf::Vector2f size) {
    mButton->setSize(size);
}

void Button::setPosition(sf::Vector2f position) {
    mButton->setPosition(position);
}

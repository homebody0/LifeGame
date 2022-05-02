#include "Figure.h"

Figure::Figure() {
    mTexture = new sf::Texture;
    mInformation = new sf::Texture;

    mSprite = new sf::Sprite;
    mSpriteInformation = new sf::Sprite;
}

Figure::~Figure() {
    delete mTexture;
    delete mInformation;

    delete mSprite;
    delete mSpriteInformation;
}

void Figure::setScale(float x, float y) {
    mSprite->setScale(x, y);
}

void Figure::setPosition(float x, float y) {
    mSprite->setPosition(x, y);
}

sf::FloatRect Figure::getGlobalBounds() {
    return mSprite->getGlobalBounds();
}

void Figure::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*mSprite);
}

sf::Sprite Figure::getSprite() {
    return *mSprite;
}

sf::Texture Figure::getTexture() {
    return *mTexture;
}

void Figure::loadFromFile(const std::string& filenameFigure, const std::string& filenameInformation) {
    mTexture->loadFromFile(filenameFigure);
    mSprite->setTexture(*mTexture);
    mInformation->loadFromFile(filenameInformation);
    mSpriteInformation->setTexture(*mInformation);
}

sf::Sprite* Figure::getInformation() {
    return mSpriteInformation;
}

void Figure::updateInformationDrawing(sf::Vector2f viewPosition, sf::Vector2f viewSize) {
    mSpriteInformation->setScale(viewSize.x / (float)mInformation->getSize().x, viewSize.y / (float)mInformation->getSize().y);
    mSpriteInformation->setPosition(viewPosition);
}

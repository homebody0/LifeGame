#include "Game.h"
#include <iostream>

Game::Game(sf::Vector2u size, const std::string& filename) {
    mField = new sf::Image();
    mField->loadFromFile(filename);

    mImageSize = new sf::Vector2u;
    *mImageSize = mField->getSize();

    mRenderSize = new sf::Vector2u;
    *mRenderSize = size;

    mFieldTexture = new sf::Texture;
    mFieldTexture->loadFromImage(*mField);

    mFieldSprite = new sf::Sprite;
    mFieldSprite->setTexture(*mFieldTexture);
}

void Game::processTicks() {
    sf::Image newField;
    newField.create(mImageSize->x, mImageSize->y);
    for (unsigned int x = 0; x < mImageSize->x; ++x) {
        for (unsigned int y = 0; y < mImageSize->y; ++y) {
            sf::Color previousState = mField->getPixel(x, y);
            unsigned int ticksNumber = ticksCount(x, y);

            if (previousState == sf::Color::White) {
                if (ticksNumber != 3 && ticksNumber != 2) {
                    newField.setPixel(x, y, sf::Color(0, 0, 0));
                }
                else {
                    newField.setPixel(x, y, sf::Color(255, 255, 255));
                }
            } else {
                if (ticksNumber == 3) {
                    newField.setPixel(x, y, sf::Color(255, 255, 255));
                }
            }
        }
    }
    *mField = newField;
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    mFieldTexture->update(*mField);
    mFieldSprite->setScale((float)target.getSize().x / mFieldTexture->getSize().x,
                           (float)target.getSize().y / mFieldTexture->getSize().y);
    target.draw(*mFieldSprite);
}

unsigned int Game::ticksCount(unsigned int x, unsigned int y) {
    int sum = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i != 0 or j != 0) {
                try {
                    if (x + i < 0 || x + i >= mImageSize->x) throw (x + i);
                    if (y + j < 0 || y + j >= mImageSize->y) throw (y + j);
                    if (mField->getPixel(x + i, y + j) == sf::Color::White) {
                        ++sum;
                    }
                } catch(...) {
                    continue;
                }
            }
        }
    }
    return sum;
}

Game::~Game() {
    delete mField;
    delete mFieldSprite;
    delete mFieldTexture;
    delete mImageSize;
    delete mRenderSize;
}

void Game::setCurrentPixel(sf::Vector2u mousePosition, sf::Color color) {
    mField->setPixel((float)(mousePosition.x % mRenderSize->x) / mRenderSize->x * mImageSize->x,
                     (float)(mousePosition.y % mRenderSize->y) / mRenderSize->y * mImageSize->y, color);
}

void Game::save(const std::string &filename) {
    mField->saveToFile(filename);
}

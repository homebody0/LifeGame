#include "Field.h"
#include <iostream>

Field::Field(sf::Vector2u size, const std::string& filename) {
    mField = new sf::Image();
    mField->loadFromFile(filename);
    mImageSize = mField->getSize();
    mRenderSize = size;
    mFieldTexture = new sf::Texture;
    mFieldTexture->loadFromImage(*mField);
    mFieldSprite = new sf::Sprite;
    mFieldSprite->setTexture(*mFieldTexture);
}

void Field::updateCells() {
    sf::Image newField;
    newField.create(mImageSize.x, mImageSize.y);
    for (unsigned int x = 0; x < mImageSize.x; ++x) {
        for (unsigned int y = 0; y < mImageSize.y; ++y) {
            sf::Color previousState = mField->getPixel(x, y);
            unsigned int ticksNumber = countCells(x, y);

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

void Field::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    mFieldTexture->update(*mField);
    mFieldSprite->setScale((float)target.getSize().x / mFieldTexture->getSize().x,
                           (float)target.getSize().y / mFieldTexture->getSize().y);
    target.draw(*mFieldSprite);
}

unsigned int Field::countCells(unsigned int x, unsigned int y) {
    int sum = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i != 0 or j != 0) {
                try {
                    if (x + i < 0 || x + i >= mImageSize.x) throw (x + i);
                    if (y + j < 0 || y + j >= mImageSize.y) throw (y + j);
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

Field::~Field() {
    delete mField;
    delete mFieldSprite;
    delete mFieldTexture;
}

void Field::addingLifeCells(sf::Event event) {

    static sf::Vector2u mousePosition;
    if (event.type == sf::Event::MouseMoved) {
        mousePosition.x = event.mouseMove.x;
        mousePosition.y = event.mouseMove.y;
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        mousePosition.x = event.mouseButton.x;
        mousePosition.y = event.mouseButton.y;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        mField->setPixel(float(mousePosition.x) / mRenderSize.x * mImageSize.x,
                         float(mousePosition.y) / mRenderSize.y * mImageSize.y, sf::Color(255, 255, 255));
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        mField->setPixel(float(mousePosition.x) / mRenderSize.x * mImageSize.x,
                         float(mousePosition.y) / mRenderSize.y * mImageSize.y, sf::Color(0, 0, 0));
    }

    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
    {
        mField->saveToFile("..\\out.png");
    }


}


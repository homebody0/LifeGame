#include "Field.h"
#include <iostream>

Field::Field(sf::Vector2u sizeWindow, const std::string& filename) {
    mField = new sf::Image();
//    mField->loadFromFile(filename);
    mField->create(sizeWindow.x / 2, sizeWindow.y / 2);
    mImageSize = mField->getSize();
//    mRenderSize = mSize;
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
//    mFieldSprite->setScale((float)target.getSize().x / mFieldTexture->getSize().x,
//                           (float)target.getSize().y / mFieldTexture->getSize().y);
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

void Field::addingLifeCells(sf::Event event, sf::Vector2f mousePosition) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        mField->setPixel((unsigned int)(mousePosition.x),
                         (unsigned int)(mousePosition.y), sf::Color(255, 255, 255));
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        mField->setPixel((unsigned int)(mousePosition.x),
                         (unsigned int)(mousePosition.y), sf::Color(0, 0, 0));
    }

    if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
    {
        mField->saveToFile("..\\out.png");
    }


}

void Field::inputFigure(const sf::Sprite& inputSprite) {
    mField->copy(inputSprite.getTexture()->copyToImage(),
                 (unsigned int)inputSprite.getPosition().x,
                 (unsigned int)inputSprite.getPosition().y,
                 sf::IntRect(inputSprite.getLocalBounds()));
}

void Field::clear() {
    for (unsigned int i = 0; i < mField->getSize().y; ++i) {
        for (unsigned int j = 0; j < mField->getSize().x; ++j) {
            mField->setPixel(j, i, sf::Color(0, 0, 0));
        }
    }
}


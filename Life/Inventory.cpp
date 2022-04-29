#include "Inventory.h"

Inventory::Inventory(sf::Vector2f sizeOneFigure, sf::Vector2u sizeWindow) {
    mSizeOneFigure = new sf::Vector2f;
    *mSizeOneFigure = sizeOneFigure;

    mBackground = new sf::RectangleShape;
    mBackground->setSize(sf::Vector2f((float)sizeWindow.x, (float)sizeWindow.y));
    mBackground->setFillColor(sf::Color(30, 30, 30));

    mFiguresSprite = new std::vector<sf::Sprite*>;

    mFiguresTexture = new std::vector<sf::Texture*>;

    mFiguresImage = new std::vector<sf::Image*>;

    mCountOfX = new int;
    *mCountOfX = (int)(((double)sizeWindow.x + sizeOneFigure.x * 0.1f) / (sizeOneFigure.x * 1.1f));
}

void Inventory::addFigure(const std::string& imageFilename) {
    mFiguresImage->push_back(new sf::Image());
    mFiguresImage->back()->loadFromFile(imageFilename);

    mFiguresTexture->push_back(new sf::Texture());
    mFiguresTexture->back()->loadFromImage(*mFiguresImage->back());

    mFiguresSprite->push_back(new sf::Sprite(*(mFiguresTexture->back())));
    //scale зависит только от длины(х) размера mSizeOneFigure
    float scale = mSizeOneFigure->x / std::max((float)mFiguresTexture->back()->getSize().x,
                                               (float)mFiguresTexture->back()->getSize().y);
    mFiguresSprite->back()->setScale(scale, scale);

    std::cout << (mFiguresSprite->size() - 1) / *mCountOfX + 1;
    mFiguresSprite->back()->setPosition(mSizeOneFigure->x * 1.1f * (float)((mFiguresSprite->size() - 1) % *mCountOfX),
                                  mSizeOneFigure->y * 1.1f * (float)((mFiguresSprite->size() - 1) / *mCountOfX));


//    mFiguresSprite->back()->setPosition(sf::Vector2f(0.0f, 0.0f));
//    mFiguresSprite->back()->setColor(sf::Color(120, 120, 120));
}

sf::Image* Inventory::getFigureAt(sf::Vector2f mousePosition) {
    for (int i = 0; i < mFiguresSprite->size(); ++i) {
        if (isFigureContainPoint(mousePosition, mFiguresSprite->at(i)->getLocalBounds())) {
            return mFiguresImage->at(i);
        }
    }
    return nullptr;
}

bool Inventory::isFigureContainPoint(sf::Vector2f pointPosition, sf::FloatRect figure) {
    return (pointPosition.x >= figure.left && pointPosition.x <= figure.left + figure.width
                                                &&
            pointPosition.y >= figure.top && pointPosition.y <= figure.top + figure.height);
}

void Inventory::scroll(float distance) {
    for(sf::Sprite* figure: *mFiguresSprite) {
        figure->move(sf::Vector2f(0.0f, distance));
    }
}

void Inventory::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*mBackground);
    for(sf::Sprite* figure: *mFiguresSprite) {
        target.draw(*figure);
    }
}

Inventory::~Inventory() {
    delete mCountOfX;
    delete mSizeOneFigure;

    for (int i = 0; i < mFiguresSprite->size(); ++i) {
        delete mFiguresSprite->at(i);
        delete mFiguresTexture->at(i);
    }
    delete mFiguresSprite;
    delete mFiguresTexture;
    delete mBackground;
}

void Inventory::openInventory(sf::Event event, bool *isInventoryOpen, bool *isStop) {
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::E) {
        if (!*isStop) {
            *isStop = true;
        }
        *isInventoryOpen = !*isInventoryOpen;
    }
}


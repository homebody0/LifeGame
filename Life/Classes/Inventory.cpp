#include "Inventory.h"

Inventory::Inventory(sf::Vector2f sizeWindow, int countOnHorizontal) {
    mCountOfX = new int;
    *mCountOfX = countOnHorizontal;

    mSizeOneFigure = new sf::Vector2f;
    *mSizeOneFigure = sf::Vector2f(sizeWindow.x / (float)(countOnHorizontal + 1), sizeWindow.y / (float)(countOnHorizontal + 1));

    mBackground = new sf::RectangleShape;
    mBackground->setSize(sizeWindow);
    mBackground->setFillColor(sf::Color(30, 30, 30));

    mFiguresSprite = new std::vector<sf::Sprite*>;

    mFiguresTexture = new std::vector<sf::Texture*>;

    mDraggingSprite = new sf::Sprite;
    mDraggingTexture = new sf::Texture;
    mDraggingSpriteNumber = new int;
    mPreviousMousePosition = new sf::Vector2f;
    mIsDragging = new bool(false);

    mScrollDistance = new float(0);
}

void Inventory::addFigure(const std::string& imageFilename) {

    mFiguresTexture->push_back(new sf::Texture());
    mFiguresTexture->back()->loadFromFile(imageFilename);

    mFiguresSprite->push_back(new sf::Sprite(*(mFiguresTexture->back())));
    //scale зависит только от длины(х) размера mSizeOneFigure
    float scale = std::min(mSizeOneFigure->x / (float)mFiguresTexture->back()->getSize().x,
                           mSizeOneFigure->y / (float)mFiguresTexture->back()->getSize().y);
    mFiguresSprite->back()->setScale(scale, scale);

    mFiguresSprite->back()->setPosition((mSizeOneFigure->x + mSizeOneFigure->x / (float)*mCountOfX) * (float)((mFiguresSprite->size() - 1) % *mCountOfX),
                                  (mSizeOneFigure->y + mSizeOneFigure->y / (float)*mCountOfX) * (float)((mFiguresSprite->size() - 1) / *mCountOfX));

//    mFiguresSprite->back()->setPosition(sf::Vector2f(0.0f, 0.0f));
//    mFiguresSprite->back()->setColor(sf::Color(120, 120, 120));
}

int Inventory::getFigureAt(sf::Vector2f mousePosition) {
    for (int i = 0; i < mFiguresSprite->size(); ++i) {
        if (mFiguresSprite->at(i)->getGlobalBounds().contains(mousePosition)) {
            return i;
        }
    }
    return -1;
}

void Inventory::scroll(sf::Event *event) {
    float distance = 20;
    if (event->type == sf::Event::MouseWheelMoved) {
        if (event->mouseWheel.delta < 0) {
            for(sf::Sprite* figure: *mFiguresSprite) {
                *mScrollDistance += distance;
            }
        } else {
            for(sf::Sprite* figure: *mFiguresSprite) {
                *mScrollDistance -= distance;
            }
        }
    }

}

void Inventory::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (*mIsDragging) {
        target.draw(*mDraggingSprite);
    } else{
        target.draw(*mBackground);
        for (sf::Sprite *figure: *mFiguresSprite) {
            target.draw(*figure);
        }
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

    delete mDraggingSprite;
    delete mDraggingTexture;
    delete mDraggingSpriteNumber;
    delete mPreviousMousePosition;
    delete mIsDragging;
}

void Inventory::openInventory(sf::Event event, bool *isInventoryOpen, bool *isStop) {
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F) {
        if (!*isStop) {
            *isStop = true;
        }
        *isInventoryOpen = !*isInventoryOpen;
    }
}

void Inventory::dragDrop(sf::Event event, sf::Vector2f mousePosition, sf::Sprite *inputSprite, bool *isInput) {
    if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (*mIsDragging) {
                *isInput = true;
                *inputSprite = *mDraggingSprite;
                *mIsDragging = false;
            } else {
                *mDraggingSpriteNumber = getFigureAt(mousePosition);
                if (*mDraggingSpriteNumber != -1) {
                    *mIsDragging = true;
                    *mDraggingSprite = *mFiguresSprite->at(*mDraggingSpriteNumber);
                    mDraggingSprite->setScale(1, 1);
                    *mPreviousMousePosition = mousePosition;
                }
            }
        } else if (event.mouseButton.button == sf::Mouse::Right) {
            *mIsDragging = false;
        }
    }
    if (*mIsDragging) {
        rotation(event);
        mDraggingSprite->move(mousePosition - *mPreviousMousePosition);
        *mPreviousMousePosition = mousePosition;
    }
}

void Inventory::updateInventoryDraw(sf::Vector2f viewPosition, sf::Vector2f viewSize) {
//    mBackground->move(move);
//    for (sf::Sprite *figure: *mFiguresSprite) {
//        figure->move(move);
//    }
    mBackground->setPosition(viewPosition);
    mBackground->setSize(viewSize);
    *mSizeOneFigure = sf::Vector2f(viewSize.x / (float)(*mCountOfX + 1), viewSize.y / (float)(*mCountOfX + 1));
    //scale зависит только от длины(х) размера mSizeOneFigure

//    for (sf::Sprite *figure: *mFiguresSprite) {
    for (int indFigure = 0; indFigure < mFiguresSprite->size(); ++indFigure) {
        float scale = std::min(mSizeOneFigure->x / (float)mFiguresTexture->at(indFigure)->getSize().x,
                               mSizeOneFigure->y / (float)mFiguresTexture->at(indFigure)->getSize().y);
        mFiguresSprite->at(indFigure)->setScale(scale, scale);
        mFiguresSprite->at(indFigure)->setPosition(viewPosition.x + (mSizeOneFigure->x + mSizeOneFigure->x / (float) *mCountOfX) * (float) (indFigure % *mCountOfX),
                            viewPosition.y + (mSizeOneFigure->y + mSizeOneFigure->y / (float) *mCountOfX) * (float) (indFigure / *mCountOfX) + *mScrollDistance);
    }
}

void Inventory::rotation(sf::Event event) {
    sf::Image newImage =  mDraggingSprite->getTexture()->copyToImage();
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Q) {
        newImage.flipHorizontally();
    }
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::E) {
        newImage.flipVertically();
    }
    mDraggingTexture->loadFromImage(newImage);
    mDraggingSprite->setTexture(*mDraggingTexture);
}
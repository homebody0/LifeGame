#include "Inventory.h"

Inventory::Inventory(sf::Vector2f sizeWindow, int countOnHorizontal) {
    mCountOfX = new int;
    *mCountOfX = countOnHorizontal;

    mIsShowInformation = new bool(false);

    mSizeOneFigure = new sf::Vector2f;

    mBackground = new sf::RectangleShape;
    mBackground->setSize(sizeWindow);
    mBackground->setFillColor(sf::Color(30, 30, 30));

    mFigures = new std::vector<Figure*>;

    mVerticalLines = new std::vector<sf::RectangleShape*>;
    mHorizontalLines = new std::vector<sf::RectangleShape*>;

    for (int i = 0; i < countOnHorizontal - 1; ++i) {
        mVerticalLines->push_back(new sf::RectangleShape);
        mVerticalLines->back()->setFillColor(sf::Color(227, 66, 52));
    }

    mDraggingSprite = new sf::Sprite;
    mDraggingTexture = new sf::Texture;
    mClickFigureNumber = new int;
    mIsDragging = new bool(false);

    mScrollDistance = new float(0);
}

void Inventory::addFigure(const std::string& imageFilename, const std::string& informationFilename) {
    mFigures->push_back(new Figure());
    mFigures->back()->loadFromFile(imageFilename, informationFilename);
    if (mFigures->size() % *mCountOfX == 1) {
        mHorizontalLines->push_back(new sf::RectangleShape);
        mHorizontalLines->back()->setFillColor(sf::Color(227, 66, 52));
    }
}

int Inventory::getFigureAt(sf::Vector2f mousePosition) {
    for (int i = 0; i < mFigures->size(); ++i) {
        if (mFigures->at(i)->getGlobalBounds().contains(mousePosition)) {
            return i;
        }
    }
    return -1;
}

void Inventory::scroll(sf::Event *event) {
    float distance = 20;
    if (event->type == sf::Event::MouseWheelMoved) {
        if (event->mouseWheel.delta < 0) {
            *mScrollDistance -= distance;
        } else {
            *mScrollDistance += distance;
        }
    }
    if (*mScrollDistance > 0) {
        *mScrollDistance = 0.0f;
    }
}

void Inventory::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (*mIsShowInformation) {
        target.draw(*mFigures->at(*mClickFigureNumber)->getInformation());
    }
    else if (*mIsDragging) {
        target.draw(*mDraggingSprite);
    } else {
        target.draw(*mBackground);
        for (Figure *figure: *mFigures) {
            target.draw(*figure);
        }
        for (sf::RectangleShape* line: *mVerticalLines) {
            target.draw(*line);
        }
        for (sf::RectangleShape* line: *mHorizontalLines) {
            target.draw(*line);
        }
    }
}

Inventory::~Inventory() {
    delete mCountOfX;
    delete mSizeOneFigure;
    delete mBackground;

    for (auto & figure : *mFigures) {
        delete figure;
    }
    delete mFigures;

    for (auto & line : *mVerticalLines) {
        delete line;
    }
    delete mVerticalLines;

    for (auto & line : *mHorizontalLines) {
        delete line;
    }
    delete mHorizontalLines;

    delete mScrollDistance;

    delete mIsShowInformation;

    delete mDraggingSprite;
    delete mDraggingTexture;
    delete mClickFigureNumber;
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
    if (event.type == sf::Event::KeyReleased && *mIsShowInformation) {
        *mIsShowInformation = false;
    } else if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (*mIsDragging) {
                *isInput = true;
                *inputSprite = *mDraggingSprite;
                *mIsDragging = false;
            } else {
                *mClickFigureNumber = getFigureAt(mousePosition);
                if (*mClickFigureNumber != -1) {
                    *mIsDragging = true;
                    *mDraggingSprite = mFigures->at(*mClickFigureNumber)->getSprite();
                    mDraggingSprite->setScale(1, 1);
                }
            }
        } else if (event.mouseButton.button == sf::Mouse::Right) {
            if (*mIsDragging) {
                *mIsDragging = false;
            } else {
                *mClickFigureNumber = getFigureAt(mousePosition);
                if (*mClickFigureNumber != -1) {
                    *mIsShowInformation = true;
                }
            }
        }
    }
    if (*mIsDragging) {
        rotation(event);
        mDraggingSprite->setPosition(mousePosition.x - (float)mDraggingTexture->getSize().x / 2,
                                     mousePosition.y - (float)mDraggingTexture->getSize().y / 2);
    }
}

void Inventory::updateInventoryDraw(sf::Vector2f viewPosition, sf::Vector2f viewSize) {
    if (*mIsShowInformation) {
        mFigures->at(*mClickFigureNumber)->updateInformationDrawing(viewPosition, viewSize);
    } else {
        mBackground->setPosition(viewPosition);
        mBackground->setSize(viewSize);
        *mSizeOneFigure = sf::Vector2f(viewSize.x / (float) (*mCountOfX + 1), viewSize.y / (float) (*mCountOfX + 1));
        //scale зависит только от длины(х) размера mSizeOneFigure

        for (int indFigure = 0; indFigure < mFigures->size(); ++indFigure) {
            float scale = std::min(mSizeOneFigure->x / (float) mFigures->at(indFigure)->getTexture().getSize().x,
                                   mSizeOneFigure->y / (float) mFigures->at(indFigure)->getTexture().getSize().y);
            mFigures->at(indFigure)->setScale(scale, scale);
            mFigures->at(indFigure)->setPosition(viewPosition.x +
                                                 (mSizeOneFigure->x + mSizeOneFigure->x / (float) (*mCountOfX - 1)) *
                                                 (float) (indFigure % *mCountOfX),
                                                 viewPosition.y +
                                                 (mSizeOneFigure->y + mSizeOneFigure->y / (float) (*mCountOfX - 1)) *
                                                 (float) (indFigure / *mCountOfX) + *mScrollDistance);
        }
        for (int indLine = 0; indLine < mVerticalLines->size(); ++indLine) {
            mVerticalLines->at(indLine)->setSize(sf::Vector2f(mSizeOneFigure->x / 100, viewSize.y));
            mVerticalLines->at(indLine)->setPosition(viewPosition.x + (mSizeOneFigure->x +
                                                                       mSizeOneFigure->x / (float) (*mCountOfX - 1)) *
                                                                      (float) ((indLine + 1) % *mCountOfX) -
                                                     (mSizeOneFigure->x / (2 + (float) (*mCountOfX - 1))),
                                                     viewPosition.y);
        }
        for (int indLine = 0; indLine < mHorizontalLines->size(); ++indLine) {
            mHorizontalLines->at(indLine)->setSize(sf::Vector2f(viewSize.x, mSizeOneFigure->y / 100));
            mHorizontalLines->at(indLine)->setPosition(viewPosition.x,
                                                       viewPosition.y + (mSizeOneFigure->x +
                                                                         mSizeOneFigure->x / (float) (*mCountOfX - 1)) *
                                                                        (float) ((indLine + 1) % *mCountOfX) -
                                                       (mSizeOneFigure->x / (2 + (float) (*mCountOfX - 1))) +
                                                       *mScrollDistance);
        }
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

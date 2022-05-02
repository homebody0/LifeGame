#include "Game.h"

Game::Game() {
    mIsFirstPlayGame = new bool(true);
    mIsFirstOpenInventory = new bool(true);
    mIsFirstPlayGameDisplayed = new bool(false);
    mIsFirstOpenInventoryDisplayed = new bool(false);
    mTextureGameControlInfo = new sf::Texture;
    mTextureGameControlInfo->loadFromFile("..\\information\\control_resume.png");
    mTextureInventoryControlInfo = new sf::Texture;
    mTextureInventoryControlInfo->loadFromFile("..\\information\\control_inventory.png");
    mGameControlInfo = new sf::Sprite;
    mGameControlInfo->setTexture(*mTextureGameControlInfo);
    mInventoryControlInfo = new sf::Sprite;
    mInventoryControlInfo->setTexture(*mTextureInventoryControlInfo);


    mPreviousViewPosition = new sf::Vector2f;

    mWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "My window");
    sf::Image image;
    image.loadFromFile("..\\figures\\glider.png");
    mWindow->setIcon(3, 3, image.getPixelsPtr());

    mCamera = new sf::View(sf::FloatRect((float)mWindow->getSize().x / 4 - (float)mWindow->getSize().x / 40,
                                         (float)mWindow->getSize().y / 4 - (float)mWindow->getSize().y / 40,
                                         (float)mWindow->getSize().x / 20,
                                         (float)mWindow->getSize().y / 20));
    *mPreviousViewPosition = mCamera->getCenter();

    mMenu = new Menu(mCamera->getSize());

    mIsStop = new bool(true);

    mIsMenuOpen = new bool(true);

    mIsInventoryOpen = new bool(false);

    mField = new Field(mWindow->getSize());

    mEvent = new sf::Event;

    mInventory = new Inventory(mCamera->getSize(), 3);

    mInventory->addFigure("..\\figures\\gunFigure.png", "..\\information\\info_gosper.png");
    mInventory->addFigure("..\\figures\\pinwheel.png", "..\\information\\info_pinwheel.png");
    mInventory->addFigure("..\\figures\\glider.png", "..\\information\\info_glaider.png");
    mInventory->addFigure("..\\figures\\pulsarCP48-56-72.png", "..\\information\\info_pulsar.png");
    mInventory->addFigure("..\\figures\\superheavySpaceship.png", "..\\information\\info_spaceship.png");
    mInventory->addFigure("..\\figures\\5-5-5-5-5-5-5.png", "..\\information\\info_5555555.png");
    mInventory->addFigure("..\\figures\\r.png", "..\\information\\info_r.png");


    while (mWindow->isOpen()) {
        processing();
    }
}

void Game::processing() {
    while (mWindow->pollEvent(*mEvent)) {
        if (mEvent->type == sf::Event::Closed) {
            mWindow->close();
        }
        Menu::openMenu(*mEvent, mIsMenuOpen, mIsStop);
        if (*mIsFirstPlayGameDisplayed || *mIsFirstOpenInventoryDisplayed) {
            closeInfo();
        } else if (!*mIsMenuOpen) {
            Inventory::openInventory(*mEvent, mIsInventoryOpen, mIsStop);
            if (!*mIsInventoryOpen) {
                if (mEvent->type == sf::Event::KeyReleased && mEvent->key.code == sf::Keyboard::C) {
                    mField->clear();
                }
                scaleView();
                moveView();
                stopGameOfClickingOnSpace();
                if (*mIsStop) {
                    mField->addingLifeCells(*mEvent, mWindow->mapPixelToCoords(sf::Mouse::getPosition(*mWindow), *mCamera));
                }
            } else {
                mInventory->scroll(mEvent);
                bool* isInput = new bool(false);
                auto* inputSprite = new sf::Sprite;
                mInventory->dragDrop(*mEvent, mWindow->mapPixelToCoords(sf::Mouse::getPosition(*mWindow), *mCamera),
                                     inputSprite, isInput);
                if (*isInput) {
                    mField->inputFigure(*inputSprite);
                }
                delete isInput;
                delete inputSprite;
            }
        } else {
            bool *isClear = new bool(false);
            mMenu->usingMenu(mWindow->mapPixelToCoords(sf::Mouse::getPosition(*mWindow), *mCamera), isClear, mIsMenuOpen,
                             mIsInventoryOpen, mWindow);
            if (*isClear) {
                mField->clear();
            }
        }
    }

    if(!*mIsStop) {
        mField->updateCells();
    } else {
    }

    mWindow->clear();

    mWindow->draw(*mField);

    mMenu->updateMenuDraw(sf::Vector2f(mCamera->getCenter().x - mCamera->getSize().x / 2,
                                       mCamera->getCenter().y - mCamera->getSize().y / 2), mCamera->getSize());
    mInventory->updateInventoryDraw(sf::Vector2f(mCamera->getCenter().x - mCamera->getSize().x / 2,
                                                 mCamera->getCenter().y - mCamera->getSize().y / 2), mCamera->getSize());
    *mPreviousViewPosition = mCamera->getCenter();

    if (*mIsMenuOpen) {
        mWindow->draw(*mMenu);
    } else if (*mIsInventoryOpen) {
        if (*mIsFirstOpenInventory) {
            mInventoryControlInfo->setScale(mCamera->getSize().x / (float)mTextureInventoryControlInfo->getSize().x,
                                       mCamera->getSize().y / (float)mTextureInventoryControlInfo->getSize().y);
            mInventoryControlInfo->setPosition(mCamera->getCenter().x - mCamera->getSize().x / 2,
                                          mCamera->getCenter().y - mCamera->getSize().y / 2);
            mWindow->draw(*mInventoryControlInfo);
            *mIsFirstOpenInventoryDisplayed = true;
        }else {
            mWindow->draw(*mInventory);
        }
    } else {
        if (*mIsFirstPlayGame) {
            mGameControlInfo->setScale(mCamera->getSize().x / (float)mTextureGameControlInfo->getSize().x,
                                       mCamera->getSize().y / (float)mTextureGameControlInfo->getSize().y);
            mGameControlInfo->setPosition(mCamera->getCenter().x - mCamera->getSize().x / 2,
                                          mCamera->getCenter().y - mCamera->getSize().y / 2);
            mWindow->draw(*mGameControlInfo);
            *mIsFirstPlayGameDisplayed = true;
        }
    }

    mWindow->setView(*mCamera);
    mWindow->display();

}

void Game::stopGameOfClickingOnSpace() {
    if(mEvent->type == sf::Event::KeyReleased && mEvent->key.code == sf::Keyboard::Space)
    {
        *mIsStop = !(*mIsStop);
    }
}

Game::~Game() {
    delete mWindow;
    delete mCamera;
    delete mPreviousViewPosition;

    delete mEvent;

    delete mIsStop;
    delete mIsMenuOpen;
    delete mIsInventoryOpen;

    delete mField;
    delete mMenu;
    delete mInventory;

    delete mIsFirstPlayGame;
    delete mIsFirstOpenInventory;
    delete mIsFirstPlayGameDisplayed;
    delete mIsFirstOpenInventoryDisplayed;
    delete mTextureGameControlInfo;
    delete mTextureInventoryControlInfo;
    delete mGameControlInfo;
    delete mInventoryControlInfo;
}

void Game::moveView() {
    float moveSpeed = 5;
    if (mEvent->type == sf::Event::KeyReleased && mEvent->key.code == sf::Keyboard::W) {
        mCamera->move(0, -moveSpeed);
    } if (mEvent->type == sf::Event::KeyReleased && mEvent->key.code == sf::Keyboard::A) {
        mCamera->move(-moveSpeed, 0);
    } if (mEvent->type == sf::Event::KeyReleased && mEvent->key.code == sf::Keyboard::S) {
        mCamera->move(0, moveSpeed);
    } if (mEvent->type == sf::Event::KeyReleased && mEvent->key.code == sf::Keyboard::D) {
        mCamera->move(moveSpeed, 0);
    }
}

void Game::scaleView() {
    if (mEvent->type == sf::Event::MouseWheelMoved) {
        float zom = 1.2f;
        if (mEvent->mouseWheel.delta < 0) {
            mCamera->zoom(zom);
        } else {
            mCamera->zoom(1.0f / zom);
        }
    }
}

void Game::closeInfo() {
    if (mEvent->type == sf::Event::KeyReleased) {
        if (*mIsFirstPlayGame && *mIsFirstPlayGameDisplayed) {
            *mIsFirstPlayGame = false;
            *mIsFirstPlayGameDisplayed = false;
        }
        if (*mIsFirstOpenInventory && *mIsFirstOpenInventoryDisplayed) {
            *mIsFirstOpenInventory = false;
            *mIsFirstOpenInventoryDisplayed = false;
        }
    }
}


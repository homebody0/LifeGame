#include "Game.h"

Game::Game() {
    mPreviousViewPosition = new sf::Vector2f;

    mCamera = new sf::View(sf::FloatRect(0.0, 0.0, 80.0, 80.0));
    *mPreviousViewPosition = mCamera->getCenter();

    mWindow = new sf::RenderWindow(sf::VideoMode(400, 400), "My window");
//    mWindow->setFramerateLimit(15);

    mMenu = new Menu(mCamera->getSize());

    mIsStop = new bool(true);

    mIsMenuOpen = new bool(true);

    mIsInventoryOpen = new bool(false);

    mField = new Field(mWindow->getSize(), "..\\gun.png");

    mEvent = new sf::Event;

    mInventory = new Inventory(mCamera->getSize(), 3);
    mInventory->addFigure("..\\gunFigure.png");

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
        scaleView();
        moveView();
        if (!*mIsMenuOpen) {
            Inventory::openInventory(*mEvent, mIsInventoryOpen, mIsStop);
            if (!*mIsInventoryOpen) {
                stopGameOfClickingOnSpace();
                if (*mIsStop) {
                    mField->addingLifeCells(*mEvent, mWindow->mapPixelToCoords(sf::Mouse::getPosition(*mWindow), *mCamera));
                }
            } else {
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
        mWindow->draw(*mInventory);
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
    delete mEvent;
    delete mIsStop;
    delete mField;
    delete mMenu;
    delete mInventory;
    delete mCamera;
    delete mIsInventoryOpen;
    delete mIsMenuOpen;
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


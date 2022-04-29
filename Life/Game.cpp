#include "Game.h"

Game::Game() {
    mWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "My window");
    mWindow->setFramerateLimit(15);

    mMenu = new Menu(mWindow->getSize());

    mIsStop = new bool(true);

    mIsMenuOpen = new bool(true);

    mIsInventoryOpen = new bool(false);

    mField = new Field(mWindow->getSize(), "..\\gun.png");

    mEvent = new sf::Event;

    mInventory = new Inventory(sf::Vector2f(200, 200), mWindow->getSize());
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
        if (!*mIsMenuOpen) {
            Inventory::openInventory(*mEvent, mIsInventoryOpen, mIsStop);
            if (!*mIsInventoryOpen) {
                stopGameOfClickingOnSpace();
                if (*mIsStop) {
                    mField->addingLifeCells(*mEvent);
                }
            }
        }
    }

    if(!*mIsStop) {
        mField->updateCells();
    } else {
    }

    mWindow->clear();
    mWindow->draw(*mField);
    if (*mIsMenuOpen) {
        mWindow->draw(*mMenu);
    } else if (*mIsInventoryOpen) {
        mWindow->draw(*mInventory);
    }
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
}


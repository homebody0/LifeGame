#include "Game.h"

Game::Game() {
    mWindow = new sf::RenderWindow(sf::VideoMode(800, 800), "My window");
    mWindow->setFramerateLimit(15);

    mIsStop = new bool(true);

    mField = new Field(mWindow->getSize(), "..\\gun.png");

    mEvent = new sf::Event;

    while (mWindow->isOpen()) {
        processing();
    }
}

void Game::processing() {
    while (mWindow->pollEvent(*mEvent)) {
        if (mEvent->type == sf::Event::Closed) {
            mWindow->close();
        }
        mField->addingLifeCells(*mEvent);
        stopGameOfClickingOnSpace();
    }

    if(!*mIsStop) {
        mField->updateCells();
    } else {
    }

    mWindow->clear();
    mWindow->draw(*mField);
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
}


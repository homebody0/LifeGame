#include "Game.h"

Game::Game(sf::Vector2u size) {
    mWindow = new sf::RenderWindow(sf::VideoMode(size.x, size.y), "Life");
    mWindow->setFramerateLimit(15);

    mEvent = new sf::Event;

    mField = new Field(size);

    mIsStop = new bool(true);

    processingEvents();
}

void Game::processingEvents() {
    while (mWindow->isOpen()) {

        while (mWindow->pollEvent(*mEvent)) {
            if (mEvent->type == sf::Event::Closed) {
                mWindow->close();
            }

            static sf::Vector2u mousePosition;
            if (mEvent->type == sf::Event::MouseMoved) {
                mousePosition.x = mEvent->mouseMove.y;
                mousePosition.y = mEvent->mouseMove.y;
            }
            if (mEvent->type == sf::Event::MouseButtonPressed) {
                mousePosition.x = mEvent->mouseButton.x;
                mousePosition.y = mEvent->mouseButton.y;
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                mField->setPixel(sf::Vector2u((float)mousePosition.x / mWindow->getSize().x * mField->getSizeField().x,
                                              (float)mousePosition.y / mWindow->getSize().y * mField->getSizeField().y),
                                 sf::Color(255, 255, 255));
            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                mField->setPixel(sf::Vector2u((float)whenMouse().x / mWindow->getSize().x * mField->getSizeField().x,
                                              (float)whenMouse().y / mWindow->getSize().y * mField->getSizeField().y),
                                 sf::Color(0, 0, 0));
            }

            if(mEvent->type == sf::Event::KeyReleased && mEvent->key.code == sf::Keyboard::Space) {
                *mIsStop = !(*mIsStop);
            }
        }

        if(!(*mIsStop)) {
            mField->updateCells();
        }

        mWindow->clear();
        draw();
        mWindow->display();
    }
}

void Game::draw() {
    mWindow->draw(*mField);
}

sf::Vector2u Game::whenMouse() {
    static sf::Vector2u mousePosition;
    if (mEvent->type == sf::Event::MouseMoved) {
        mousePosition.x = mEvent->mouseMove.y;
        mousePosition.y = mEvent->mouseMove.y;
    }
    if (mEvent->type == sf::Event::MouseButtonPressed) {
        mousePosition.x = mEvent->mouseButton.x;
        mousePosition.y = mEvent->mouseButton.y;
    }
    return mousePosition;
}

Game::~Game() {
    delete mWindow;
    delete mEvent;
    delete mField;
    delete mIsStop;
}


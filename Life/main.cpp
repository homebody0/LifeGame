#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace sf;

int main() {
    Game well(sf::Vector2u(800, 800));
//    RenderWindow window(sf::VideoMode(800, 800), "My window");
//    window.setFramerateLimit(15);
//    Field myField(window.getSize(), "..\\gun.png");
//    bool isStop = false;
//    int i = 1;
//
//    while (window.isOpen()) {
//
//        Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == Event::Closed) {
//                window.close();
//            }
//            myField.processEvent(event);
//        }
//        if (!myField.isStop()) {
//            myField.updateCells();
//        }
//
//        window.clear();
//        window.draw(myField);
//        window.display();
//    }

    return 0;
}
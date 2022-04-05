#include <SFML/Graphics.hpp>
#include <iostream>
#include "Field.h"

using namespace sf;

int main() {
    RenderWindow window(sf::VideoMode(800, 800), "My window");
    window.setFramerateLimit(15);
    Field myField(window.getSize(), "..\\gun.png");

    int i = 1;

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            myField.processEvent(event);
        }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            myField.processTicks();
            ++i;
        }

        window.clear();
        window.draw(myField);
        window.display();
    }

    return 0;
}
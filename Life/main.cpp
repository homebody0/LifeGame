#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    window.setFramerateLimit(15);
    Game myField(window.getSize(), "..\\gun.png");

    bool isStop = true;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            static sf::Vector2u mousePosition;
            if (event.type == sf::Event::MouseMoved) {
                mousePosition.x = event.mouseMove.x;
                mousePosition.y = event.mouseMove.y;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                mousePosition.x = event.mouseButton.x;
                mousePosition.y = event.mouseButton.y;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                myField.setCurrentPixel(mousePosition, sf::Color(255, 255, 255));

            }
            else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                myField.setCurrentPixel(mousePosition, sf::Color(0, 0, 0));
            }

            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
            {
                myField.save("..\\out.png");
            }

            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
            {
                isStop = !isStop;
            }
        }
        if (!isStop) {
            myField.processTicks();
        }

        window.clear();
        window.draw(myField);
        window.display();
    }

    return 0;
}
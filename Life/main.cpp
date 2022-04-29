#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

using namespace sf;

int main() {

    Game well;
    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
    window.setFramerateLimit(15);

    sf::RectangleShape background(sf::Vector2f(800.0f, 800.0f));
    background.setFillColor(sf::Color(0,0,0));

    sf::Texture texture;
    texture.loadFromFile("..\\gunFigure.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(200/(float)texture.getSize().x, 200/(float)texture.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        }

        window.clear();
        window.draw(background);
        window.draw(sprite);
        window.display();
    }
    return 0;
}
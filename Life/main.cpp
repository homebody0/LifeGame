#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Game.h"

using namespace sf;

int main() {

    Game well;



//    sf::View camera(sf::FloatRect(0.0f, 0.0f, 80.0f, 80.0f));
//
//    sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
//
//    sf::RectangleShape background(sf::Vector2f(800.0f, 800.0f));
//    background.setFillColor(sf::Color(120,120,120));
//
//    sf::Texture texture;
//    texture.loadFromFile("..\\gunFigure.png");
//
//    sf::Sprite sprite;
//    sprite.setTexture(texture);
//
//    sf::Texture texture1;
//    texture1.loadFromImage(texture.copyToImage());
//
//    bool isDrag = false;
//    sf::Vector2f mouseToOriginDistance;
//    sf::Vector2f mouse;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
//                mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//                isDrag = !isDrag;
//            }
//            if(isDrag) {
//                sprite.move(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window)) - mouse));
//                mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//            }
//            if (event.type == sf::Event::MouseWheelMoved) {
//                float zom = 1.2f;
//                if (event.mouseWheel.delta < 0) {
//                    camera.zoom(zom);
//                } else {
//                    camera.zoom(1.0f / zom);
//                }
//            }
//        }
//
//        window.clear();
//        window.draw(background);
//        window.draw(sprite);
//        window.setView(camera);
//        window.display();
//    }
//    return 0;


//    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Views", sf::Style::Fullscreen);
//    sf::Clock timeFromStartup;
//    window.setFramerateLimit(60);
//
//    sf::Texture backgroundTexture;
//    backgroundTexture.loadFromFile("..\\viewTry\\cityBackground.jpg");
//    sf::Sprite background;
//    background.setTexture(backgroundTexture);
//    background.setScale(3,3);
//
//    sf::Texture playerTexture;
//    playerTexture.loadFromFile("..\\viewTry\\PixelArt.png");
//    sf::Sprite player;
//    player.setTexture(playerTexture);
//    player.setScale(0.5,0.5);
//
//    const float PLAYER_SPEED = 20;
//
//    sf::View miniMap;
//    miniMap = window.getDefaultView();
//
//    miniMap.setViewport(sf::FloatRect(0.75, 0.75, 0.25, 0.25));
//    miniMap.zoom(6.5);
//
//    while (window.isOpen()) {
//        sf::Event event;
//
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//        {
//            player.move(0, -PLAYER_SPEED);
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//        {
//            player.move(0, PLAYER_SPEED);
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//        {
//            player.move(-PLAYER_SPEED, 0);
//        }
//        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//        {
//            player.move(PLAYER_SPEED, 0);
//        }
//
//
//        window.clear();
//
//        sf::View playerView = window.getDefaultView();
//        playerView.setCenter(player.getPosition().x + player.getTexture()->getSize().x / 2, player.getPosition().y + player.getTexture()->getSize().y / 2);
////        playerView.rotate(sin(timeFromStartup.getElapsedTime().asSeconds()) * 30);
//        window.setView(playerView);
//
//        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
//        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
//
//        if(player.getGlobalBounds().contains(worldPos))
////        if(player.getGlobalBounds().contains(sf::Vector2f(pixelPos.x, pixelPos.y)))
//        {
//            player.setColor(sf::Color::Green);
//        } else {
//            player.setColor(sf::Color::White);
//        }
//
//        window.draw(background);
//        window.draw(player);
//
//        window.setView(miniMap);
//
//        pixelPos = sf::Mouse::getPosition(window);
//        worldPos = window.mapPixelToCoords(pixelPos);
//
//        if(player.getGlobalBounds().contains(worldPos))
//        {
//            background.setColor(sf::Color::Red);
//        } else {
//            background.setColor(sf::Color::White);
//        }
//
//        window.draw(background);
//        window.draw(player);
//
//        window.display();
//    }
}
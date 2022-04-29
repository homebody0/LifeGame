#ifndef LIFE_INVENTORY_H
#define LIFE_INVENTORY_H

#include "SFML/Graphics.hpp"
#include "vector"
#include "iostream"

class Inventory: public sf::Drawable{
public:
    Inventory(sf::Vector2f sizeOneFigure, sf::Vector2u sizeWindow);
    void addFigure(const std::string& imageFilename);
    void scroll(float distance);
    static void openInventory(sf::Event event, bool *isInventoryOpen, bool *isStop);
    sf::Image* getFigureAt(sf::Vector2f mousePosition);
    ~Inventory() override;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    static bool isFigureContainPoint(sf::Vector2f pointPosition, sf::FloatRect figure);
    std::vector<sf::Sprite*>* mFiguresSprite;
    std::vector<sf::Texture*>* mFiguresTexture;
    std::vector<sf::Image*>* mFiguresImage;
    int* mCountOfX;
    sf::Vector2f* mSizeOneFigure;
    sf::RectangleShape* mBackground;
};

#endif //LIFE_INVENTORY_H

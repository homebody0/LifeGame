#ifndef LIFE_INVENTORY_H
#define LIFE_INVENTORY_H

#include "SFML/Graphics.hpp"
#include "vector"
#include "iostream"

class Inventory: public sf::Drawable{
public:
    Inventory(sf::Vector2f sizeWindow, int countOnHorizontal);
    void addFigure(const std::string& imageFilename);
    void scroll(sf::Event *event);
    void updateInventoryDraw(sf::Vector2f viewPosition, sf::Vector2f viewSize);
    void dragDrop(sf::Event event, sf::Vector2f mousePosition, sf::Sprite *inputSprite, bool *isInput);
    static void openInventory(sf::Event event, bool *isInventoryOpen, bool *isStop);
    ~Inventory() override;
private:
    void rotation(sf::Event event);
    int getFigureAt(sf::Vector2f mousePosition);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    std::vector<sf::Sprite*>* mFiguresSprite;
    std::vector<sf::Texture*>* mFiguresTexture;
    int* mCountOfX;
    sf::Vector2f* mSizeOneFigure;
    sf::RectangleShape* mBackground;

    float* mScrollDistance;

    sf::Sprite* mDraggingSprite;
    sf::Texture* mDraggingTexture;
    int* mDraggingSpriteNumber;
    sf::Vector2f* mPreviousMousePosition;
    bool* mIsDragging;
};

#endif //LIFE_INVENTORY_H

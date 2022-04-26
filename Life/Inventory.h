#ifndef LIFE_INVENTORY_H
#define LIFE_INVENTORY_H

#include "SFML/Graphics.hpp"
#include "vector"

class Inventory: public sf::Drawable{
public:
    Inventory();
    void addFigure(sf::Texture texture, int i, int j);
    void scroll(float distance);
    sf::Image getFigureAt(int index);
    ~Inventory();
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    std::vector<sf::RectangleShape*>* mFigures;
};

#endif //LIFE_INVENTORY_H

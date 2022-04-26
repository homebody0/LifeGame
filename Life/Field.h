#ifndef LIFE_FIELD_H
#define LIFE_FIELD_H

#include <SFML/Graphics.hpp>

class Field : public sf::Drawable{
public:
    Field(sf::Vector2u mSize, const std::string& filename);
    void updateCells();
    unsigned int countCells(unsigned int x, unsigned int y);
    void addingLifeCells(sf::Event event);
    ~Field() override;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2u mImageSize;
    sf::Vector2u mRenderSize;
    sf::Image* mField;
    sf::Texture* mFieldTexture;
    sf::Sprite* mFieldSprite;
};

#endif //LIFE_FIELD_H

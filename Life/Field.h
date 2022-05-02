#ifndef LIFE_FIELD_H
#define LIFE_FIELD_H

#include <SFML/Graphics.hpp>

class Field : public sf::Drawable{
public:
    Field(sf::Vector2u sizeWindow, const std::string& filename);
    void updateCells();
    void addingLifeCells(sf::Event event, sf::Vector2f mousePosition);
    void inputFigure(const sf::Sprite& inputSprite);
    ~Field() override;
private:
    unsigned int countCells(unsigned int x, unsigned int y);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2u mImageSize;
    sf::Vector2f mRenderSize;
    sf::Image* mField;
    sf::Texture* mFieldTexture;
    sf::Sprite* mFieldSprite;
};

#endif //LIFE_FIELD_H

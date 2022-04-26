#ifndef LIFE_FIELD_H
#define LIFE_FIELD_H

#include <SFML/Graphics.hpp>

class Field : public sf::Drawable{
public:
    Field(sf::Vector2u mSize);
    void updateCells();
    void save(std::string& filename);
    void upload(const std::string& filename);
    void setPixel(sf::Vector2u position, sf::Color color);
    sf::Vector2u getSizeField();
//    void processEvent(sf::Event event);
//    bool isStop();
    ~Field() override;
private:
    unsigned int countCells(unsigned int x, unsigned int y);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2u* mImageSize;
    sf::Vector2u* mRenderSize;
    sf::Image* mFieldImage;
    sf::Texture* mFieldTexture;
    sf::Sprite* mFieldSprite;
//    bool* mIsStop;
};

#endif //LIFE_FIELD_H

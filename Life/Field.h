#ifndef LIFE_FIELD_H
#define LIFE_FIELD_H

#include <SFML/Graphics.hpp>

class Field : public sf::Drawable{
public:
    Field(sf::Vector2u mSize, const std::string& filename);
    void processTicks();
    unsigned int ticksCount(unsigned int x, unsigned int y);
    void processEvent(sf::Event event);
    bool isStop();
    ~Field() override;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2u mImageSize;
    sf::Vector2u mRenderSize;
    sf::Image* mField;
    sf::Texture* mFieldTexture;
    sf::Sprite* mFieldSprite;
    bool* mIsStop;
};

#endif //LIFE_FIELD_H

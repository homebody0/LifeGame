#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include <SFML/Graphics.hpp>

class Game : public sf::Drawable{
public:
    Game(sf::Vector2u mSize, const std::string& filename);
    void processTicks();
    void setCurrentPixel(sf::Vector2u mousePosition, sf::Color color);
    void save(const std::string& filename);
    ~Game() override;
private:
    unsigned int ticksCount(unsigned int x, unsigned int y);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2u* mImageSize;
    sf::Vector2u* mRenderSize;
    sf::Image* mField;
    sf::Texture* mFieldTexture;
    sf::Sprite* mFieldSprite;
};

#endif //LIFE_GAME_H

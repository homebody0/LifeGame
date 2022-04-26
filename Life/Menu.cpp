#include "Menu.h"

Menu::Menu(sf::Vector2<unsigned int> sizeWindow) {
    mButtonsSize = new sf::Vector2f(200, 100);

    mButtons = new std::vector<Button*>{
        new Button("../resume.png", *mButtonsSize, sf::Vector2f(sizeWindow.x / 2 - mButtonsSize->x / 2,
                                                                sizeWindow.y / 2 - 2 * mButtonsSize->y)),

        new Button("../figures.png", *mButtonsSize, sf::Vector2f(sizeWindow.x / 2 - mButtonsSize->x / 2,
                                                                sizeWindow.y / 2 - mButtonsSize->y)),

        new Button("../settings.png", *mButtonsSize, sf::Vector2f(sizeWindow.x / 2 - mButtonsSize->x / 2,
                                                                sizeWindow.y / 2)),

        new Button("../exit.png", *mButtonsSize, sf::Vector2f(sizeWindow.x / 2 - mButtonsSize->x / 2,
                                                                sizeWindow.y / 2 + mButtonsSize->y))
    };

}

Menu::~Menu() {
    delete mButtonsSize;
    for (auto & button : *mButtons) {
        delete button;
    }
    delete mButtons;
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (auto & button : *mButtons) {
        target.draw(*button);
    }
}

void Menu::openMenu(sf::Event event, bool* isMenuOpen, bool* isStop) {
    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape){
        if (!*isStop) {
            *isStop = true;
        }
        *isMenuOpen = !*isMenuOpen;
    }
}

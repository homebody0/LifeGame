#include "Menu.h"

Menu::Menu(sf::Vector2f viewSize) {
    sf::Vector2f buttonsSize = sf::Vector2f(viewSize.x / 4, viewSize.x / 8);

    mButtons = new std::vector<Button*>{
        new Button("../resume.png", buttonsSize, sf::Vector2f(viewSize.x / 2 - buttonsSize.x / 2,
                                                              viewSize.y / 2 - 2 * buttonsSize.y)),

        new Button("../inventory.png", buttonsSize, sf::Vector2f(viewSize.x / 2 - buttonsSize.x / 2,
                                                               viewSize.y / 2 - buttonsSize.y)),

        new Button("../clear.png", buttonsSize, sf::Vector2f(viewSize.x / 2 - buttonsSize.x / 2,
                                                                viewSize.y / 2)),

        new Button("../exit.png", buttonsSize, sf::Vector2f(viewSize.x / 2 - buttonsSize.x / 2,
                                                            viewSize.y / 2 + buttonsSize.y))
    };

}

Menu::~Menu() {
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

void Menu::updateMenuDraw(sf::Vector2f viewPosition, sf::Vector2f viewSize) {
    sf::Vector2f buttonsSize = sf::Vector2f(viewSize.x / 4, viewSize.x / 8);
    float biasVertical = 0;
    for (Button* button: *mButtons) {
        button->setPosition(viewPosition + sf::Vector2f(viewSize.x / 2 - buttonsSize.x / 2,
                                                        viewSize.y / 2 - 2 * buttonsSize.y + biasVertical));
        button->setSize(buttonsSize);
        biasVertical += buttonsSize.y;
    }
}

void Menu::usingMenu(sf::Vector2f mousePosition, bool *isClear, bool *isMenuOpen, bool *isInventoryOpen,
                     sf::RenderWindow *window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (mButtons->at(RESUME)->isClick(mousePosition)) {
            *isMenuOpen = false;
        } else if (mButtons->at(FIGURES)->isClick(mousePosition)) {
            *isInventoryOpen = true;
            *isMenuOpen = false;
        } else if (mButtons->at(CLEAR)->isClick(mousePosition)) {
            *isClear = true;
        } else if (mButtons->at(EXIT)->isClick(mousePosition)) {
            window->close();
        }
    }
}

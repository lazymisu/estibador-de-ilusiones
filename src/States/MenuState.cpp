#include "MenuState.hpp"
#include "../Game.hpp"
#include <iostream>

MenuState::MenuState(Game& game) 
    : GameState(game)
    , font_(FONT_PATH)
    , backgroundTexture_(MENU_BACKGROUND_PATH)
    , backgroundSprite_(backgroundTexture_)
    , currentOption_(0)
{
    std::vector<std::string> options = { "Empezar", "Opciones", "Salir" };
    float menuY = 116;

    for (const std::string& text : options) {
        sf::Text option(font_, text, 32);
        option.setPosition({ 32, menuY });
        menuText_.push_back(option);
        menuY += 64;
    }

    float scale = WINDOW_WIDTH / backgroundSprite_.getLocalBounds().size.x;
    backgroundSprite_.setScale({ scale, scale });
};

void MenuState::handleInput(sf::Event event) {
    if (event.is<sf::Event::KeyPressed>()) {
        const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();

        // std::string key = sf::Keyboard::getDescription(keyEvent->scancode);
        // std::cout << key << std::endl;

        if (keyEvent->code == sf::Keyboard::Key::Down) {
            if (currentOption_ == menuText_.size() - 1) {
                currentOption_ = 0;
            } else {
                currentOption_++;
            }
        }

        if (keyEvent->code == sf::Keyboard::Key::Up) {
            if (currentOption_ == 0) {
                currentOption_ = menuText_.size() - 1;
            } else {
                currentOption_--;
            }
        }
    }

    if (event.is<sf::Event::KeyReleased>()) {
        const auto& keyEvent = event.getIf<sf::Event::KeyReleased>();

        if (keyEvent->code == sf::Keyboard::Key::Enter) {
            switch (currentOption_) {
                case 0: // NEW_GAME
                    std::cout << "NEW_GAME" << std::endl;
                    break;
                case 1: // SETTINGS
                    std::cout << "SETTINGS" << std::endl;
                    break;
                case 2: // EXIT
                    game_.closeWindow();
                    break;
                default:
                    break;
            }
        }
    }
}

void MenuState::update(sf::Time dt) {
    for (int i = 0; i < menuText_.size(); i++) {
        if (i == currentOption_) {
            menuText_[i].setFillColor({ 255, 0, 0 });
        } else {
            menuText_[i].setFillColor({ 0, 0, 0 });
        }
    }
}

void MenuState::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite_);

    for (int i = 0; i < menuText_.size(); i++) {
        window.draw(menuText_[i]);
    }
}

std::string MenuState::getName() const {
    return "MenuState";
}

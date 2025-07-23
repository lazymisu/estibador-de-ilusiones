#include "MenuState.hpp"
#include "../Game.hpp"
#include "SettingsState.hpp"
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <memory>

enum MenuOptions {
    NEW_GAME, SETTINGS, EXIT
};

MenuState::MenuState(Game& game) 
    : GameState(game)
    , backgroundSprite_(game_.g_resources.get(TextureID::MenuBG))
{
    std::vector<std::string> options = { "Nueva Partida", "Opciones", "Salir" };
    float menuX = (BASE_WINDOW_WIDTH / 2) - (BUTTON_SIZE.x / 2);
    float menuY = static_cast<float>(BASE_WINDOW_HEIGHT) / 2;

    for (const std::string& text : options) {
        menuButtons_.push_back(
            Button(
                menuX, menuY, text, 
                game_.g_resources.get(FontID::MainFont), 
                game_.g_resources.get(TextureID::ButtonBG)
            )
        );
        menuY += menuButtons_.back().getBounds().size.y + 32;
    }
};

void MenuState::handleInput(sf::Event event, sf::RenderWindow& window) {
    const auto& keyEvent = event.getIf<sf::Event::KeyPressed>();
    // std::string key = sf::Keyboard::getDescription(keyEvent->scancode);
    // std::cout << key << std::endl;

    for (int i = 0; i < menuButtons_.size(); i++) {
        menuButtons_[i].handleInput(event, window);

        if (const auto* mouseReleased = event.getIf<sf::Event::MouseButtonReleased>()) {
            if (mouseReleased->button == sf::Mouse::Button::Left && menuButtons_[i].isHovered)
            {
                switch (i) {
                    case NEW_GAME:
                        std::cout << "NEW_GAME" << std::endl;
                        break;
                    case SETTINGS:
                        game_.pushState(std::make_unique<SettingsState>(game_));
                        break;
                    case EXIT:
                        window.close();
                        break;
                }
            }
        }
    }
}

void MenuState::update(sf::Time dt, sf::RenderWindow& window) {
    for (int i = 0; i < menuButtons_.size(); i++) {
       menuButtons_[i].update(dt, window);
    }
}

void MenuState::draw(sf::RenderWindow& window) {
    window.draw(backgroundSprite_);

    for (int i = 0; i < menuButtons_.size(); i++) {
       menuButtons_[i].draw(window);
    }
}

std::string MenuState::getName() const {
    return "MenuState";
}

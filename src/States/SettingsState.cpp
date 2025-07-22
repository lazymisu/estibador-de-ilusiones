#include "SettingsState.hpp"
#include "GameState.hpp"
#include "../Game.hpp"

SettingsState::SettingsState(Game& game)
    : GameState(game)
    , font_(FONT_PATH)
    , texture_(GUI_BUTTON_PATH)
    , btnBack(200, 200, "Atras", font_, texture_)
{

}

void SettingsState::handleInput(sf::Event event, sf::RenderWindow& window) {
    btnBack.handleInput(event, window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && btnBack.isHovered) {
        game_.popState();
    }
}

void SettingsState::update(sf::Time dt, sf::RenderWindow& window) {
    btnBack.update(dt, window);
}

void SettingsState::draw(sf::RenderWindow& window) {
    btnBack.draw(window);
}

std::string SettingsState::getName() const {
    return "SettingsState";
}

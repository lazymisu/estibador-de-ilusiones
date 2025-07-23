#include "SettingsState.hpp"
#include "GameState.hpp"
#include "../Game.hpp"

SettingsState::SettingsState(Game& game)
    : GameState(game)
    , m_backButton(50, 50, "Atras", game_.g_resources.get(FontID::MainFont), game_.g_resources.get(TextureID::ButtonBG))
    , m_backgroundSprite(game_.g_resources.get(TextureID::MenuBG))
    , m_containerSprite(game_.g_resources.get(TextureID::ContainerBG))
{
    m_backgroundSprite.setPosition({ 0, 0 });
    m_containerSprite.setOrigin(m_containerSprite.getLocalBounds().getCenter());
    m_containerSprite.setPosition(m_backgroundSprite.getGlobalBounds().getCenter());
}

void SettingsState::handleInput(sf::Event event, sf::RenderWindow& window) {
    m_backButton.handleInput(event, window);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_backButton.isHovered) {
        game_.popState();
    }
}

void SettingsState::update(sf::Time dt, sf::RenderWindow& window) {
    m_backButton.update(dt, window);
}

void SettingsState::draw(sf::RenderWindow& window) {
    window.draw(m_backgroundSprite);
    window.draw(m_containerSprite);
    m_backButton.draw(window);
}

std::string SettingsState::getName() const {
    return "SettingsState";
}

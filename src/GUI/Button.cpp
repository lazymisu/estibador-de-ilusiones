#include "Button.hpp"

Button::Button(float x, float y, 
               const std::string& text, 
               const sf::Font& font, 
               const sf::Texture& texture)
    : sprBackground(texture)
    , txtTitle(font, text, 32)
    , rect(static_cast<sf::Vector2f>(BUTTON_SIZE))
{
    rect.setFillColor({ 0, 0, 0 });
    rect.setPosition({ x, y });

    sprBackground.setPosition(rect.getPosition());

    txtTitle.setFillColor(sf::Color::White);
    txtTitle.setOrigin({
        txtTitle.getLocalBounds().position.x + txtTitle.getLocalBounds().size.x / 2,
        txtTitle.getLocalBounds().position.y + txtTitle.getLocalBounds().size.y / 2
    });
    txtTitle.setPosition({
        x + rect.getGlobalBounds().size.x / 2,
        y + rect.getGlobalBounds().size.y / 2
    });
}

void Button::handleInput(sf::Event event, sf::RenderWindow& window) {
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    isHovered = rect.getGlobalBounds().contains(mousePos);
}

void Button::update(sf::Time dt, sf::RenderWindow& window) {
    if (isHovered) {
        sprBackground.setTextureRect(BUTTON_HOVER_RECT);
    } else {
        sprBackground.setTextureRect(BUTTON_NORMAL_RECT);
    }
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(sprBackground);
    window.draw(txtTitle);
}

sf::FloatRect Button::getBounds() const {
    return rect.getGlobalBounds();
}

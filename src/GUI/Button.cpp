#include "Button.hpp"

Button::Button(float x, float y, const std::string &text, const sf::Font &font,
               const sf::Texture &texture)
    : background_sprite_(texture), title_text_(font, text, 32),
      rect_(static_cast<sf::Vector2f>(kButtonSize)) {
  rect_.setFillColor({0, 0, 0});
  rect_.setPosition({x, y});

  background_sprite_.setPosition(rect_.getPosition());

  title_text_.setFillColor(sf::Color::White);
  title_text_.setOrigin({title_text_.getLocalBounds().position.x +
                             title_text_.getLocalBounds().size.x / 2,
                         title_text_.getLocalBounds().position.y +
                             title_text_.getLocalBounds().size.y / 2});
  title_text_.setPosition({x + rect_.getGlobalBounds().size.x / 2,
                           y + rect_.getGlobalBounds().size.y / 2});
}

void Button::handleInput(sf::Event event, sf::RenderWindow &window) {
  sf::Vector2f mousePos =
      window.mapPixelToCoords(sf::Mouse::getPosition(window));
  isHovered = rect_.getGlobalBounds().contains(mousePos);
}

void Button::update(sf::Time dt, sf::RenderWindow &window) {
  auto rect = isHovered ? kButtonHoverRect : kButtonNormalRect;
  background_sprite_.setTextureRect(rect);
}

void Button::draw(sf::RenderWindow &window) {
  window.draw(background_sprite_);
  window.draw(title_text_);
}

const sf::FloatRect Button::getBounds() const {
  return rect_.getGlobalBounds();
}

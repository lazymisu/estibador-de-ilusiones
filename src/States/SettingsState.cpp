#include "SettingsState.hpp"

SettingsState::SettingsState(GameContext &context)
    : GameState(context),
      back_button_(50, 50, "Atras",
                   context_.asset_manager.get(FontID::MainFont),
                   context_.asset_manager.get(TextureID::ButtonBG)),
      background_sprite_(context_.asset_manager.get(TextureID::MenuBG)),
      container_sprite_(context_.asset_manager.get(TextureID::ContainerBG)) {
  container_sprite_.setOrigin(background_sprite_.getGlobalBounds().getCenter());
  container_sprite_.setPosition(
      background_sprite_.getGlobalBounds().getCenter());
}

void SettingsState::handleInput(sf::Event event) {
  back_button_.handleInput(event, context_.window);

  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) &&
      back_button_.isHovered) {
    // todo: fixear
    // context_.popState();
  }
}

void SettingsState::update(sf::Time dt) {
  back_button_.update(dt, context_.window);
}

void SettingsState::draw(sf::RenderWindow &window) {
  window.draw(background_sprite_);
  window.draw(container_sprite_);
  back_button_.draw(window);
}

std::string SettingsState::getName() const { return "SettingsState"; }

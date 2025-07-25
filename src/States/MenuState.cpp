#include "MenuState.hpp"

// todo: refactor
enum class MenuOptions { NEW_GAME, SETTINGS, EXIT };

MenuState::MenuState(GameContext &context)
    : GameState(context),
      background_sprite_(context_.asset_manager.get(TextureID::MenuBG)) {
  std::vector<std::string> options = {"Nueva Partida", "Opciones", "Salir"};
  float menuX = (kBaseWindowWidth / 2) - (kButtonSize.x / 2);
  float menuY = static_cast<float>(kBaseWindowHeight) / 2;

  for (const std::string &text : options) {
    menu_buttons_.push_back(
        Button(menuX, menuY, text, context_.asset_manager.get(FontID::MainFont),
               context_.asset_manager.get(TextureID::ButtonBG)));
    menuY += menu_buttons_.back().getBounds().size.y + 32;
  }
};

void MenuState::handleInput(sf::Event event) {
  const auto &keyEvent = event.getIf<sf::Event::KeyPressed>();
  // std::string key = sf::Keyboard::getDescription(keyEvent->scancode);
  // std::cout << key << std::endl;

  for (int i = 0; i < menu_buttons_.size(); i++) {
    menu_buttons_[i].handleInput(event, context_.window);

    if (const auto *mouseReleased =
            event.getIf<sf::Event::MouseButtonReleased>()) {
      if (mouseReleased->button == sf::Mouse::Button::Left &&
          menu_buttons_[i].isHovered) {
        switch (i) {
        case static_cast<int>(MenuOptions::NEW_GAME):
          std::cout << "NEW_GAME" << std::endl;
          break;
        case static_cast<int>(MenuOptions::SETTINGS):
          // todo: fixear
          // context_.pushState(std::make_unique<SettingsState>(game_));
          break;
        case static_cast<int>(MenuOptions::EXIT):
          // todo: fixear
          // window.close();
          break;
        default:
          break;
        }
      }
    }
  }
}

void MenuState::update(sf::Time dt) {
  for (int i = 0; i < menu_buttons_.size(); i++) {
    menu_buttons_[i].update(dt, context_.window);
  }
}

void MenuState::draw(sf::RenderWindow &window) {
  window.draw(background_sprite_);

  for (int i = 0; i < menu_buttons_.size(); i++) {
    menu_buttons_[i].draw(window);
  }
}

std::string MenuState::getName() const { return "MenuState"; }

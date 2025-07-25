#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "../GUI/Button.hpp"
#include "../Utils/Definitions.hpp"
#include "GameState.hpp"
#include "SettingsState.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class MenuState : public GameState {
public:
  MenuState(GameContext &context);

  void handleInput(sf::Event event) override;
  void update(sf::Time dt) override;
  void draw(sf::RenderWindow &window) override;

  std::string getName() const override;

private:
  std::vector<Button> menu_buttons_;
  sf::Sprite background_sprite_;
};

#endif // !MENU_STATE_HPP

#ifndef SETTINGS_STATE_HPP
#define SETTINGS_STATE_HPP

#include "../GUI/Button.hpp"
#include "../Utils/ResourceHolder.hpp"
#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SettingsState : public GameState {
public:
  SettingsState(GameContext &context);

  void handleInput(sf::Event eventindow) override;
  void update(sf::Time dt) override;
  void draw(sf::RenderWindow &window) override;

  std::string getName() const override;

private:
  Button back_button_;
  sf::Sprite background_sprite_;
  sf::Sprite container_sprite_;
};

#endif // !SETTINGS_STATE_HPP

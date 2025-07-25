#ifndef GAME_HPP
#define GAME_HPP

#include "States/GameState.hpp"
#include "States/MenuState.hpp"
#include "Utils/Definitions.hpp"
#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>
#include <memory>

class Game {
public:
  Game();
  ~Game();

  void run();

  void pushState(std::unique_ptr<GameState> state);
  void popState();
  void changeState(std::unique_ptr<GameState> state);

private:
  void initWindow();
  void handleEvents();
  void update(sf::Time dt);
  void render();

  sf::RenderWindow window_;
  sf::Clock clock_;
  sf::View game_view_;
  std::vector<std::unique_ptr<GameState>> game_states_;

  ResourceHolder asset_manager_;
  GameContext context_;

  // todo: refactor
  bool show_state_debug_window = false;
};

#endif // !GAME_HPP

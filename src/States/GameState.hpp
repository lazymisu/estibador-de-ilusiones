#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "../Utils/ResourceHolder.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

struct GameContext {
  sf::RenderWindow &window;
  ResourceHolder &asset_manager;
};

class GameState {
public:
  GameState(GameContext &context) : context_(context) {}
  virtual ~GameState() = default;

  virtual void handleInput(sf::Event event) = 0;
  virtual void update(sf::Time dt) = 0;
  virtual void draw(sf::RenderWindow &window) = 0;

  virtual std::string getName() const = 0;

protected:
  GameContext &context_;
};

#endif // !GAME_STATE_HPP

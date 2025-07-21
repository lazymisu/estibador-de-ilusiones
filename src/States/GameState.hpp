#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game;

class GameState {
public:
    GameState(Game& game): game_(game) {}
    virtual ~GameState() = default;

    virtual void handleInput(sf::Event event) = 0;
    virtual void update(sf::Time dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual std::string getName() const = 0;

protected:
    Game& game_;
};

#endif // !GAME_STATE_HPP

#ifndef GAME_HPP
#define GAME_HPP

#include "States/GameState.hpp"
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <memory>
#include "States/MenuState.hpp"
#include "Utils/Definitions.hpp"

class Game {
public:
    Game();
    ~Game();
    void run();
    void closeWindow();

private:
    sf::RenderWindow window_;
    sf::Clock clock_;
    std::vector<std::unique_ptr<GameState>> states_;

    void initWindow();
    void handleEvents();
    void update(sf::Time dt);
    void render();
    void pushState(std::unique_ptr<GameState> state);
    void popState();
    void changeState(std::unique_ptr<GameState> state);
};

#endif // !GAME_HPP

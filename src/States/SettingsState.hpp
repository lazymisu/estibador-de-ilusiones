#ifndef SETTINGS_STATE_HPP
#define SETTINGS_STATE_HPP

#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../GUI/Button.hpp"
#include "../Utils/Definitions.hpp"

class Game;

class SettingsState : public GameState {
public:
    SettingsState(Game& game);
    virtual ~SettingsState() = default;

    void handleInput(sf::Event event, sf::RenderWindow& window) override;
    void update(sf::Time dt, sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    std::string getName() const override;

private:
    // resource holder
    sf::Font font_;
    sf::Texture texture_;

    Button btnBack; 
};

#endif // !SETTINGS_STATE_HPP

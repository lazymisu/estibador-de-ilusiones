#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Utils/Definitions.hpp"

class MenuState : public GameState {
public:
    MenuState(Game& game);
    virtual ~MenuState() = default;

    void handleInput(sf::Event event) override;
    void update(sf::Time dt) override;
    void draw(sf::RenderWindow& window) override;
    std::string getName() const override;

private:
    const sf::Font font_;
    std::vector<sf::Text> menuText_;
    int currentOption_;
    const sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;
};

#endif // !MENU_STATE_HPP

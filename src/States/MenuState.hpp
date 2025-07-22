#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "GameState.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Utils/Definitions.hpp"
#include "../GUI/Button.hpp"

class MenuState : public GameState {
public:
    MenuState(Game& game);
    virtual ~MenuState() = default;

    void handleInput(sf::Event event, sf::RenderWindow& window) override;
    void update(sf::Time dt, sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    std::string getName() const override;

private:
    // resource holder
    sf::Font font_;
    sf::Texture texture_;

    std::vector<std::unique_ptr<Button>> menuButtons_;
    sf::Texture backgroundTexture_;
    sf::Sprite backgroundSprite_;
};

#endif // !MENU_STATE_HPP

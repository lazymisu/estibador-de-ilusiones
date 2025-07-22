#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Utils/Definitions.hpp"
#include <string>

class Button {
public:
    Button(
        float x, float y, 
        const std::string& text, 
        const sf::Font& font, 
        const sf::Texture& texture
    );

    ~Button() = default;

    void handleInput(sf::Event event, sf::RenderWindow& window);
    void update(sf::Time dt, sf::RenderWindow& window);
    void draw(sf::RenderWindow &window);

    sf::FloatRect getBounds() const;

    bool isHovered = false;

private:
    sf::RectangleShape rect;
    sf::Sprite sprBackground;
    sf::Text txtTitle;
};

#endif // !BUTTON_HPP

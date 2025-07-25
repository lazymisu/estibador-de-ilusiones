#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../Utils/Definitions.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

class Button {
public:
  Button(float x, float y, const std::string &text, const sf::Font &font,
         const sf::Texture &texture);

  void handleInput(sf::Event event, sf::RenderWindow &window);
  void update(sf::Time dt, sf::RenderWindow &window);
  void draw(sf::RenderWindow &window);

  const sf::FloatRect getBounds() const;

  bool isHovered = false;

private:
  sf::RectangleShape rect_;
  sf::Sprite background_sprite_;
  sf::Text title_text_;
};

#endif // !BUTTON_HPP

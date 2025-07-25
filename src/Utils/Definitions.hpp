#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

const float kBaseWindowWidth = 1920;
const float kBaseWindowHeight = 1080;
const int kWindowWidth = 1280;
const int kWindowHeight = 720;
const std::string kGameTitle = "Estibador de Ilusiones";
const int kFramerate = 144;

// - Assets
const std::string kFontPath = "assets/fonts/Monaco.ttf";
const std::string kMenuBackgroundPath = "assets/textures/menu_background.png";
const std::string kButtonPath = "assets/textures/gui_button.png";
const std::string kContainerPath = "assets/textures/box_container.png";

// - Spritesheets
const sf::Vector2i kButtonSize = {400, 105};
const sf::IntRect kButtonNormalRect({0, 0}, kButtonSize);
const sf::IntRect kButtonHoverRect({0, 105}, kButtonSize);

#endif // !DEFINITIONS_HPP

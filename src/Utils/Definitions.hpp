#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

const float BASE_WINDOW_WIDTH = 1920;
const float BASE_WINDOW_HEIGHT = 1080;
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const std::string GAME_TITLE = "Estibador de Ilusiones";
const int FRAMERATE = 144;

// - Assets
const std::string FONT_PATH = "assets/fonts/Monaco.ttf";
const std::string MENU_BACKGROUND_PATH = "assets/textures/menu_background.png";
const std::string GUI_BUTTON_PATH = "assets/textures/gui_button.png";
const std::string BOX_CONTAINER_PATH = "assets/textures/box_container.png";

// - Spritesheets
const sf::Vector2i BUTTON_SIZE = { 400, 105 };
const sf::IntRect BUTTON_NORMAL_RECT({ 0, 0 }, BUTTON_SIZE);
const sf::IntRect BUTTON_HOVER_RECT({ 0, 105 }, BUTTON_SIZE);

#endif // !DEFINITIONS_HPP

#include "ResourceHolder.hpp"

ResourceHolder::ResourceHolder() {
  load(TextureID::MenuBG, kMenuBackgroundPath);
  load(TextureID::ContainerBG, kContainerPath);
  load(TextureID::ButtonBG, kButtonPath);
  load(FontID::MainFont, kFontPath);
}

void ResourceHolder::load(TextureID id, const std::string &path) {
  sf::Texture texture;
  if (!texture.loadFromFile(path)) {
    throw std::runtime_error("Failed to load texture: " + path);
  }
  textures_[id] = std::move(texture);
}

const sf::Texture &ResourceHolder::get(TextureID id) const {
  try {
    return textures_.at(id);
  } catch (const std::out_of_range &e) {
    throw std::runtime_error(
        "Texture not found: " + std::to_string(static_cast<int>(id)) +
        ". Error: " + e.what());
  }
}

void ResourceHolder::load(FontID id, const std::string &path) {
  sf::Font font;
  if (!font.openFromFile(path)) {
    throw std::runtime_error("Failed to load font: " + path);
  }
  fonts_[id] = std::move(font);
}

const sf::Font &ResourceHolder::get(FontID id) const {
  try {
    return fonts_.at(id);
  } catch (const std::out_of_range &e) {
    throw std::runtime_error(
        "Font not found: " + std::to_string(static_cast<int>(id)) +
        ". Error: " + e.what());
  }
}

#include "ResourceHolder.hpp"

ResourceHolder::ResourceHolder() {
  std::vector<FontID> fonts = {MainFont};
  for (FontID font : fonts) {
    add(font);
  }

  std::vector<TextureID> textures = {MenuBG, ButtonBG, ContainerBG};
  for (TextureID texture : textures) {
    add(texture);
  }
}

ResourceHolder::~ResourceHolder() { 
    m_fonts.clear();
    m_textures.clear();
}

const sf::Font &ResourceHolder::get(FontID id) const {
  auto it = m_fonts.find(id);

  if (it != m_fonts.end()) {
    return it->second;
  } else {
    exit(EXIT_FAILURE);
  }
}

void ResourceHolder::add(FontID id) {
  switch (id) {
  case FontID::MainFont:
    m_fonts[id] = sf::Font(FONT_PATH);
    break;
  default:
    break;
  }
}

const sf::Texture &ResourceHolder::get(TextureID id) const {
  auto it = m_textures.find(id);

  if (it != m_textures.end()) {
    return it->second;
  } else {
    exit(EXIT_FAILURE);
  }
}

void ResourceHolder::add(TextureID id) {
  switch (id) {
  case TextureID::MenuBG:
    m_textures[id] = sf::Texture(MENU_BACKGROUND_PATH);
    break;
  case TextureID::ButtonBG:
    m_textures[id] = sf::Texture(GUI_BUTTON_PATH);
    break;
  case TextureID::ContainerBG:
    m_textures[id] = sf::Texture(BOX_CONTAINER_PATH);
    break;
  default:
    break;
  }
}

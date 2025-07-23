#include "ResourceHolder.hpp"

ResourceHolder::ResourceHolder() {
    m_fontPaths[FontID::MainFont] = FONT_PATH;

    m_texturePaths[TextureID::MenuBG] = MENU_BACKGROUND_PATH;
    m_texturePaths[TextureID::ButtonBG] = GUI_BUTTON_PATH;
    m_texturePaths[TextureID::ContainerBG] = BOX_CONTAINER_PATH;

    for (const auto &pair : m_fontPaths) {
        load(pair.first, pair.second);
    }

    for (const auto &pair : m_texturePaths) {
        load(pair.first, pair.second);
    }
}

const sf::Font& ResourceHolder::get(FontID id) const {
    auto it = m_fonts.find(id);

    if (it != m_fonts.end()) {
        return it->second;
    } else {
        exit(EXIT_FAILURE);
    }
}

const sf::Texture& ResourceHolder::get(TextureID id) const {
    auto it = m_textures.find(id);

    if (it != m_textures.end()) {
        return it->second;
    } else {
        exit(EXIT_FAILURE);
    }
}

void ResourceHolder::load(FontID id, const std::string &path) {
    m_fonts[id] = sf::Font(path);
}

void ResourceHolder::load(TextureID id, const std::string &path) {
    m_textures[id] = sf::Texture(path);
}

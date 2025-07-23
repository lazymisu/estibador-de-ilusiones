#ifndef RESOURCE_HOLDER_HPP
#define RESOURCE_HOLDER_HPP

#include <SFML/Graphics/Font.hpp>
#include <map>
#include "Definitions.hpp"

enum class FontID { MainFont };

enum class TextureID { MenuBG, ButtonBG, ContainerBG };

class ResourceHolder {
public:
    ResourceHolder();

    const sf::Font& get(FontID id) const;
    const sf::Texture& get(TextureID id) const;

private:
    std::map<FontID, sf::Font> m_fonts;
    std::map<TextureID, sf::Texture> m_textures;

    std::map<FontID, std::string> m_fontPaths;
    std::map<TextureID, std::string> m_texturePaths;

    void load(FontID id, const std::string& path);
    void load(TextureID id, const std::string& path);
};

#endif // !RESOURCE_HOLDER_HPP

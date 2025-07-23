#ifndef RESOURCE_HOLDER_HPP
#define RESOURCE_HOLDER_HPP

#include <SFML/Graphics/Font.hpp>
#include <map>
#include "Definitions.hpp"

enum FontID { MainFont };

enum TextureID { MenuBG, ButtonBG, ContainerBG };

class ResourceHolder {
public:
  ResourceHolder();
  ~ResourceHolder();

  const sf::Font& get(FontID id) const;
  const sf::Texture& get(TextureID id) const;

private:
  std::map<FontID, sf::Font> m_fonts;
  std::map<TextureID, sf::Texture> m_textures;

  void add(FontID id);
  void add(TextureID id);
};

#endif // !RESOURCE_HOLDER_HPP

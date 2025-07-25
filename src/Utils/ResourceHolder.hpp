#ifndef RESOURCE_HOLDER_HPP
#define RESOURCE_HOLDER_HPP

#include "Definitions.hpp"
#include <SFML/Graphics/Font.hpp>
#include <map>

// todo: refactor
enum class FontID { MainFont };
enum class TextureID { MenuBG, ButtonBG, ContainerBG };

class ResourceHolder {
public:
  ResourceHolder();

  const sf::Font &get(FontID id) const;
  const sf::Texture &get(TextureID id) const;

private:
  std::map<FontID, sf::Font> fonts_;
  std::map<TextureID, sf::Texture> textures_;

  void load(FontID id, const std::string &path);
  void load(TextureID id, const std::string &path);
};

#endif // !RESOURCE_HOLDER_HPP

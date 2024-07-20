#pragma once

#include "BaseManager.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Resources {
public:
  BaseManager<sf::Texture> textures {};
  BaseManager<sf::SoundBuffer> audio {};
  BaseManager<sf::Font> fonts {};

  static Resources& getInstance() {
    static Resources instance;
    return instance;
  }
  
protected:
  Resources() = default;
};
#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

inline void center_origin(sf::Sprite& sprite) {
  sprite.setOrigin(sprite.getLocalBounds().width / 2.f, sprite.getLocalBounds().height / 2.f);
}

inline void center_origin(sf::Text& text) {
  auto center = text.getGlobalBounds().getSize() / 2.f;
	auto local_bounds = center + text.getLocalBounds().getPosition();
	auto rounded = sf::Vector2f(std::round(local_bounds.x), std::round(local_bounds.y));
	text.setOrigin(rounded);
}
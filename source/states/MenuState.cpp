#include "states/MenuState.hpp"
#include "states/LevelState.hpp"
#include "utility/CenterOrigin.hpp"
#include "GameContext.hpp"

MenuState::MenuState() : m_button(m_resources.textures.preload("start", "assets/start.png")) {
  center_origin(m_button);
  m_button.setPosition(320, 400);
}

void MenuState::update(sf::Event& event, sf::RenderWindow& window) {
  if (event.type == sf::Event::MouseButtonPressed) {
    if (m_button.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(window))) {
      m_context->switch_state(new LevelState(1));
    }
  }
}

void MenuState::render(sf::RenderWindow& window) {
  sf::Sprite screen { m_resources.textures.get("menu") };

  window.draw(screen);
  window.draw(m_button);
}
#include "states/GameOverState.hpp"
#include "GameContext.hpp"
#include "states/MenuState.hpp"
#include "utility/CenterOrigin.hpp"

GameOverState::GameOverState() : m_button(m_resources.textures.get("tryagain")) {
  center_origin(m_button);
  m_button.setPosition(320, 400);
}

void GameOverState::update(sf::Event& event, sf::RenderWindow& window) {
  sf::Vector2f mouse = (sf::Vector2f) sf::Mouse::getPosition(window);
  
  if (event.type == sf::Event::MouseButtonPressed) {
    if (m_button.getGlobalBounds().contains(mouse)) {
      m_context->switch_state(new MenuState());
    }
  }
}

void GameOverState::render(sf::RenderWindow& window) {
  sf::Sprite image { m_resources.textures.get("gameover") };

  window.draw(image);
  window.draw(m_button);
}
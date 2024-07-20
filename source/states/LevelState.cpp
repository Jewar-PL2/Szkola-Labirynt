#include "states/LevelState.hpp"
#include "states/GameOverState.hpp"
#include "utility/CenterOrigin.hpp"
#include "states/JumpscareState.hpp"
#include "GameContext.hpp"
#include <string>

LevelState::LevelState(int number) : m_level_number(number), m_start_button(m_resources.textures.get("start")) {
  std::string name = "level" + std::to_string(m_level_number);
  m_level.setTexture(m_resources.textures.get(name));
  center_origin(m_start_button);

  sf::Vector2f button_pos;

  switch (m_level_number) {
    case 1: button_pos = { 64, 136 }; break;
    case 2: button_pos = { 64, 414 }; break;
    case 3: button_pos = { 80, 410 }; break;
    case 4: m_context->switch_state(new JumpscareState()); break;
    default: break;
  }

  m_start_button.setPosition(button_pos);
}

void LevelState::update(sf::Event &event, sf::RenderWindow &window) {
  sf::Vector2f mouse = (sf::Vector2f) sf::Mouse::getPosition(window);

  if (event.type == sf::Event::MouseButtonPressed) {
    if (m_level_started) return;

    if (m_start_button.getGlobalBounds().contains(mouse)) {
      m_level_started = true;
      return;
    }
  }

  if (event.type == sf::Event::MouseMoved) {
    if (m_level_started && 
      m_level
        .getTexture()
        ->copyToImage()
        .getPixel((int) mouse.x, (int) mouse.y) == sf::Color::Black
      ) {
      m_context->switch_state(new GameOverState());
    }

    if (m_level_started && 
      m_level
        .getTexture()
        ->copyToImage()
        .getPixel((int) mouse.x, (int) mouse.y) == sf::Color::Red
      ) {
      m_context->switch_state(new LevelState(++m_level_number));
    }

    if (m_level_started && m_level_number == 3 && mouse.y <= 122) m_context->switch_state(new JumpscareState());
  }
}

void LevelState::render(sf::RenderWindow &window) {
  window.draw(m_level);

  if (!m_level_started)
    window.draw(m_start_button);
}
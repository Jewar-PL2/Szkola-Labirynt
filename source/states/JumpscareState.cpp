#include "states/JumpscareState.hpp"
#include "utility/CenterOrigin.hpp"

JumpscareState::JumpscareState() 
  : m_jumpscare(m_resources.textures.get("jumpscare")), 
    m_jumpscareSound(m_resources.audio.get("jumpscare")) 
{
  m_jumpscareSound.play();
}

void JumpscareState::update(sf::Event& event, sf::RenderWindow& window) {
  (void) event;
  (void) window;
}

void JumpscareState::render(sf::RenderWindow& window) {
  sf::Text haha("ZOSTALES STROLLOWANY", m_resources.fonts.get("roboto"), 48);
  sf::Text haha2("DOSTANE ZA TO CHOCIAZ 2?", m_resources.fonts.get("roboto"), 48);
  center_origin(haha);
  center_origin(haha2);
  haha.setFillColor(sf::Color::Red);
  haha2.setFillColor(sf::Color::Red);
  haha.setPosition(320, 32);
  haha2.setPosition(320, 448);

  window.draw(m_jumpscare);
  if (timer.getElapsedTime().asSeconds() > 1.5f) {
    window.draw(haha);
    window.draw(haha2);
  } 
}
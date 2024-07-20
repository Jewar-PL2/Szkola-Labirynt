#pragma once

#include "GameState.hpp"
#include "utility/Resources.hpp"

class JumpscareState : public GameState {
public:
  JumpscareState();
  virtual ~JumpscareState() = default;

  void update(sf::Event& event, sf::RenderWindow& window) override;
  void render(sf::RenderWindow& window) override;

private:
  Resources& m_resources = Resources::getInstance();

  sf::Sprite m_jumpscare;
  sf::Sound m_jumpscareSound;
  sf::Clock timer;
};
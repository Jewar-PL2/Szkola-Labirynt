#pragma once

#include "GameState.hpp"
#include "utility/Resources.hpp"

class GameOverState : public GameState {
public:
  GameOverState();
  virtual ~GameOverState() = default;

  void update(sf::Event& event, sf::RenderWindow& window) override;
  void render(sf::RenderWindow& window) override;

private:
  Resources& m_resources = Resources::getInstance();
  sf::Sprite m_button;
};
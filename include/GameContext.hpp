#pragma once

#include "GameState.hpp"

class GameContext {
public:
  GameContext(GameState* state);

  ~GameContext();

  void update(sf::Event& event, sf::RenderWindow& window);

  void render(sf::RenderWindow& window);

  void switch_state(GameState* state);
private:
  GameState* m_currentState;
};
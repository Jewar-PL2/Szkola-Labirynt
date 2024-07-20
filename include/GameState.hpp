#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GameContext;

class GameState {
public:
  virtual ~GameState() = default;

  void set_context(GameContext* context);

  virtual void update(sf::Event& event, sf::RenderWindow& window) = 0;
  virtual void render(sf::RenderWindow& window) = 0;

protected:
  GameContext* m_context;
};
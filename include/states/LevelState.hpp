#pragma once

#include "GameState.hpp"
#include "utility/Resources.hpp"

class LevelState : public GameState {
public:
  LevelState(int number);
  virtual ~LevelState() = default;

  void update(sf::Event &event, sf::RenderWindow &window) override;
  void render(sf::RenderWindow &window) override;

private:
  Resources& m_resources = Resources::getInstance();

  int m_level_number;
  bool m_level_started = false;

  sf::Sprite m_level;
  sf::Sprite m_start_button;
};
#include "GameContext.hpp"

GameContext::GameContext(GameState* state) : m_currentState(nullptr) { switch_state(state); }

GameContext::~GameContext() { delete m_currentState; }

void GameContext::update(sf::Event &event, sf::RenderWindow& window) { m_currentState->update(event, window); }

void GameContext::render(sf::RenderWindow &window) { m_currentState->render(window); }

void GameContext::switch_state(GameState *state) {
  if (m_currentState) {
    delete m_currentState;
  }
  m_currentState = state;
  m_currentState->set_context(this);
}
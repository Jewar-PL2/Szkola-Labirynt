#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "GameContext.hpp"
#include "states/MenuState.hpp"
#include "utility/Resources.hpp"

class Game {
public:
  Game() : m_window(sf::VideoMode(640, 480), "Labirynt", sf::Style::Fullscreen), m_context(new MenuState()) {
    m_window.setFramerateLimit(60);
    m_window.setVerticalSyncEnabled(true);

    m_resources.textures.preload("menu", "assets/menu.png");
    m_resources.textures.preload("level1", "assets/level1.png");
    m_resources.textures.preload("level2", "assets/level2.png");
    m_resources.textures.preload("level3", "assets/level3.png");
    m_resources.textures.preload("gameover", "assets/gameover.png");
    m_resources.textures.preload("jumpscare", "assets/jumpscare.png");

    m_resources.textures.preload("tryagain", "assets/tryagain.png");

    m_resources.audio.preload("jumpscare", "assets/jumpscare.mp3");

    m_resources.fonts.preload("roboto", "assets/Roboto.ttf");
  }

  void start() {
    while (m_window.isOpen()) {
      for (sf::Event event; m_window.pollEvent(event);) {
        m_context.update(event, m_window);

        if (event.type == sf::Event::Closed) m_window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) m_window.close();
      }
      
      m_window.clear();
      m_context.render(m_window);
      m_window.display();
    }
  }

private:
  sf::RenderWindow m_window;
  GameContext m_context;
  Resources& m_resources = Resources::getInstance();
};


int main() {

  Game maze {};
  maze.start();

  return 0;
}

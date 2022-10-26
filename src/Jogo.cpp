#include "Jogo.hpp"
#include "constants/Constants.hpp"
#include "manager/GraphicManager.hpp"
#include <SFML/Graphics.hpp>

using namespace Gerenciadores;

Jogo::Jogo(): JogadorUm() {};
Jogo::~Jogo(){};

void Jogo::executar() {
  sf::RenderWindow *window = GraphicManager::getInstance()->getWindow();

  while (window->isOpen()) {
    sf::Event event;
    while (window->pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window->close();
      } else if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
          window->close();
        }
      }
    }
  }
};
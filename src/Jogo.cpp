#include "Jogo.hpp"
#include "manager/GraphicManager.hpp"

#include <SFML/Graphics.hpp>

using namespace Entidades::Personagens;
using namespace Gerenciadores;

const string Jogo::nome = "Jogo 2d";

Jogo::Jogo() : JogadorUm(sf::Vector2f(0.0f, 0.0f), false) {
  this->graphicManager = GraphicManager::getInstance();
};
Jogo::~Jogo(){};

void Jogo::executar() {
  sf::RenderWindow *window = this->graphicManager->getWindow();

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

    window->clear();
    this->JogadorUm.executar();
    window->draw(*JogadorUm.getSprite());
    window->display();
  }
};

const string Jogo::getNome() { return Jogo::nome; }
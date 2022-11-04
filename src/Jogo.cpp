#include "Jogo.hpp"
#include "manager/GraphicManager.hpp"
#include "utils/Math.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace Utils;
using namespace Entidades::Obstaculos;
using namespace Entidades::Personagens;
using namespace Gerenciadores;

const std::string Jogo::nome = "Jogo 2d";

Jogo::Jogo()
    : JogadorUm(sf::Vector2f(24, 24), false), morcego(sf::Vector2f(24, 24)),
      blocoUm(sf::Vector2f(8, 8)), blocoDois(sf::Vector2f(8, 24)),
      caixaUm(sf::Vector2f(24, 8)), entidades() {
  srand(time(NULL));

  this->graphicManager = GraphicManager::getInstance();

  this->entidades.push(static_cast<Entidade *>(&JogadorUm));
  this->entidades.push(static_cast<Entidade *>(&morcego));
  this->entidades.push(static_cast<Entidade *>(&blocoUm));
  this->entidades.push(static_cast<Entidade *>(&blocoDois));
  this->entidades.push(static_cast<Entidade *>(&caixaUm));
};
Jogo::~Jogo(){
	// Destruir o singleton "GraphicManager"
	// ...
};

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
    this->entidades.executar();
    this->entidades.draw();
    window->display();
  }
};

const std::string Jogo::getNome() { return Jogo::nome; }
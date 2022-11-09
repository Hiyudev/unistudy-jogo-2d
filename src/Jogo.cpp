#include "Jogo.hpp"
#include "manager/GraphicManager.hpp"
#include "utils/Math.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace Utils;
using namespace Fases;
using namespace Gerenciadores;
using namespace Entidades::Personagens;

const std::string Jogo::nome = "Jogo 2d";

Jogo::Jogo()
    : JogadorUm(sf::Vector2f(32, 32), false),
      JogadorDois(sf::Vector2f(32, 32), true), faseUm() {
  srand(time(NULL));

  faseUm.insertPlayer(&JogadorUm);
  faseUm.insertPlayer(&JogadorDois);

  this->graphicManager = GraphicManager::getInstance();
};
Jogo::~Jogo() { delete GraphicManager::getInstance(); };

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
    this->faseUm.executar();
    window->display();
  }
};

const std::string Jogo::getNome() { return Jogo::nome; }
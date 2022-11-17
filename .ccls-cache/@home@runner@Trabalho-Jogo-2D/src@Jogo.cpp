#include "Jogo.hpp"
#include "class/Fase/Fase.hpp"
#include "class/Fases/Caverna.hpp"
#include "class/Fases/Ruinas.hpp"
#include "manager/GraphicManager.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace Fases;
using namespace Gerenciadores;
using namespace Entidades::Personagens;

const std::string Jogo::nome = "Jogo 2d";
bool Jogo::hasJogadorDois = false;

Jogo::Jogo()
    : JogadorUm(sf::Vector2f(32, 32), false),
      JogadorDois(sf::Vector2f(32, 32), true), menu() {
  srand(time(NULL));

  this->graphicManager = GraphicManager::getInstance();
};

Jogo::~Jogo() {
  if (this->graphicManager != NULL) {
    delete this->graphicManager;
  }
};

void Jogo::executar() {
  sf::RenderWindow *window = this->graphicManager->getWindow();

  while (window->isOpen()) {
    // std::cout << "Loop..." << '\n';
    window->clear();
    if (menu.getStarted() == true) {
      if (fase == NULL) {
        if (this->menu.getWorldID() == 1) {
          std::cout << "Caverna..." << '\n';
          this->fase = new Caverna();
        } else {
          std::cout << "Ruinas..." << '\n';
          this->fase = new Ruinas();
        }

        std::cout << "Generate world" << '\n';
        this->fase->generate();
      }
      this->fase->executar();
    } else {
      menu.executar();
    }
    window->display();
  }
};

const std::string Jogo::getNome() { return Jogo::nome; }
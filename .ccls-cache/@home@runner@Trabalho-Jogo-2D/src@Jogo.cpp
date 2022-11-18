#include "Jogo.hpp"
#include "class/Fase/Fase.hpp"
#include "class/Fases/Caverna.hpp"
#include "class/Fases/Ruina.hpp"
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

  this->fase = NULL;
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
    window->clear();

    if (menu.getStarted() == true) {
      if (this->fase == NULL) {
        if (this->menu.getWorldID() == 1) {
          this->fase = new Caverna();
        } else {
          this->fase = new Ruina();
        }

        this->fase->generate();
        Jogador *jogadorUmClone = JogadorUm.clone();
        this->fase->insertEntidade(static_cast<Entidade *>(jogadorUmClone));

        if (this->menu.getPlayersCount() == 2) {
          Jogador *jogadorDoisClone = JogadorDois.clone();
          this->fase->insertEntidade(static_cast<Entidade *>(jogadorDoisClone));
        }
      }

      if (Jogador::dead == true) {
        this->menu.setStarted(false);

        delete this->fase;
        this->fase = NULL;
        Jogador::dead = false;
      } else {
        this->fase->executar();
      }
    } else {
      this->menu.executar();
    }
    window->display();
  }
};

const std::string Jogo::getNome() { return Jogo::nome; }
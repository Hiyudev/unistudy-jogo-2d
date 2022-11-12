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
bool Jogo::hasJogadorDois = false;

Jogo::Jogo()
    : JogadorUm(sf::Vector2f(32, 32), false),
      JogadorDois(sf::Vector2f(32, 32), true), faseCaverna(),
      menu(GraphicManager::getInstance()->getWindow(), &faseCaverna) {
  srand(time(NULL));

  faseCaverna.insertPlayer(&JogadorUm);

  if (hasJogadorDois == true) {
    faseCaverna.insertPlayer(&JogadorDois);
  }

  this->graphicManager = GraphicManager::getInstance();
};
Jogo::~Jogo() { delete GraphicManager::getInstance(); };

void Jogo::executar() {
  sf::RenderWindow *window = this->graphicManager->getWindow();

  while (window->isOpen()) {
    

    window->clear();
    // this->faseUm.executar();
    menu.executar();
    window->display();
  }
};

const std::string Jogo::getNome() { return Jogo::nome; }
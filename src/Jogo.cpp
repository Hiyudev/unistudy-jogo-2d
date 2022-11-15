#include "Jogo.hpp"
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
      JogadorDois(sf::Vector2f(32, 32), true), faseCaverna(), faseRuinas(),
      menu() {
  srand(time(NULL));

  faseCaverna.insertPlayer(&JogadorUm);
  faseRuinas.insertPlayer(&JogadorUm);

  this->graphicManager = GraphicManager::getInstance();
};

Jogo::~Jogo() { delete GraphicManager::getInstance(); };

void Jogo::executar() {
  sf::RenderWindow *window = this->graphicManager->getWindow();

  while (window->isOpen()) {
    // std::cout << "Loop..." << '\n';
    window->clear();
		if(menu.getStarted() == true) {
			
  		if (this->menu.getPlayersCount() == 2) {
		    faseCaverna.insertPlayer(&JogadorDois);
		    faseRuinas.insertPlayer(&JogadorDois);
		  }

			if(this->menu.getWorldID() == 1) {
    		this->faseCaverna.executar();
			} else {
				this->faseRuinas.executar();
			}
		} else {
    	menu.executar();
		}
    window->display();
  }
};

const std::string Jogo::getNome() { return Jogo::nome; }
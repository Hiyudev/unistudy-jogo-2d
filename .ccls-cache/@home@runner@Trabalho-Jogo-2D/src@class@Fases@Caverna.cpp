#include "Caverna.hpp"
#include "../Bloco/Bloco.hpp"
#include "../Caixa/Caixa.hpp"
#include "../Ghoul/Ghoul.hpp"
#include "../Morcego/Morcego.hpp"
#include "map"
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace Entidades::Obstaculos;
using namespace Fases;

Caverna::Caverna() : Fase() { srand(time(NULL)); };

Caverna::~Caverna(){};

void Caverna::executar() { this->lista->executar(); };

void Caverna::createMap(){
  this->createBorda(0);

  // Plataforma
  for (int i = 16; i < 400; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 120)));
  }

  for (int i = 448; i > 80; i -= 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 200)));
  }
}

void Caverna::generate() {
  this->createMap();
  this->createObstaculos(1);
  this->createInimigos(4);
};

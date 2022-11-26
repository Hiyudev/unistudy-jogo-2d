#include "Caverna.hpp"
#include "map"
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace Fases;

Caverna::Caverna() : Fase() { srand(time(NULL)); };

Caverna::~Caverna(){};

void Caverna::executar() { this->lista->executar(); };

void Caverna::createMap() {
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

  sf::Vector2f vPlataformas[5] = {{200, 168}, {72, 248}, {152, 280},
                                  {296, 264}, {376, 248}};
  sf::Vector2f vInimigos[10] = { {184, 104}, {376, 184}, {152, 232}, {88, 264}, {296, 248}};
  
  int instanciasObst = 3 + (rand() % 3);
  int instanciasIni = 3 + (rand() % 3);

  for (int i = 0; i < instanciasObst; i++) {
    this->createPlataforma(vPlataformas[i].x, vPlataformas[i].y);
  }
  for(int j = 0; j < instanciasIni; j++){
    this->createMorcego(vInimigos[j].x + 32, vInimigos[j].y);
    this->createGhoul(vInimigos[j].x, vInimigos[j].y);
  }
  this->pushEntidades();
};

#include "Caverna.hpp"
#include "map"
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace Fases;

Caverna::Caverna() : Fase() { 
  srand(time(NULL)); 
};

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

  sf::Vector2f vPlataformas[6] = { {184, 168}, {40, 248}, {200, 280}, {264, 328}, {280, 72}, {328, 248}};
  
  int numInstancias = rand()%7;
  if(numInstancias < 3 ) { numInstancias = 3; }
  for(int i = 0, j = 0; i < numInstancias; i++, j++){
    this->createPlataforma(vPlataformas[j].x, vPlataformas[j].y);
    this->createMorcego(vPlataformas[j].x - 16, vPlataformas[j].y - 16);
    this->createGhoul(vPlataformas[j].x + 16, vPlataformas[j].y + 16);
  }
  this->pushEntidades();
};

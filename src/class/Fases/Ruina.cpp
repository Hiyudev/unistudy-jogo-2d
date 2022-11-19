#include "Ruina.hpp"
#include <SFML/Graphics.hpp>

using namespace Fases;

Ruina::Ruina() : Fase() { srand(time(NULL)); }

Ruina::~Ruina() {}

void Ruina::createMap() {
  this->createBorda(0);

  // Plataformas
  for (int i = 16; i < 184; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i + 8, 104)));
  }

  for (int i = 192; i < 264; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i + 8, 88)));
  }

  for (int i = 464; i > 336; i -= 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i - 8, 168)));
  }

  this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(328, 184)));
  this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(312, 184)));

  for(int i = 304; i > 96; i-= 16){
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i - 8, 168)));
  }

  for (int i = 16; i < 224; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 264)));
  }
  
}

void Ruina::generate() {
  this->createMap();

  sf::Vector2f vPlataformas[6] = { {168, 132}, {328, 104}, {376, 280}, {264, 248}, {56, 56}};
  sf::Vector2f vEspinhos[7] = { {124, 152}, {40, 248}, {312, 168}, {152, 296}, {168, 296}, {132, 296}, {328, 296}};

  int numInstancias = rand()%7; 
  if(numInstancias < 3) { numInstancias = 3;}
 
  for(int i = 0, j = 0; i < numInstancias; i++, j++){
    if(j < 5)
      this->createPlataforma(vPlataformas[j].x, vPlataformas[j].y);
    this->createEspinho(vEspinhos[j].x, vEspinhos[j].y);
    this->createGhoul(vPlataformas[j].x + 16, vPlataformas[j].y + 16);
  }
  this->pushEntidades();
}

void Ruina::executar() { this->lista->executar(); }

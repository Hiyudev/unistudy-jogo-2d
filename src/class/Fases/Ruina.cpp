#include "Ruina.hpp"
#include "../Projetil/Projetil.hpp"
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

  for (int i = 304; i > 160; i -= 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i - 8, 168)));
  }

  for (int i = 16; i < 224; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 264)));
  }
}

void Ruina::generate() {
  this->createMap();

  sf::Vector2f vPlataformas[5] = {
      {168, 132}, {328, 104}, {376, 280}, {264, 248}, {40, 56}};
  sf::Vector2f vEspinhos[7] = { {40, 248},  {312, 168}, {152, 296},
                               {168, 296}, {132, 296}, {328, 296}};

  sf::Vector2f vGhouls[10] = {};
  sf::Vector2f vCeifadores[10] = {};

  int numInstancias = rand() % 7;
  if (numInstancias < 3) {
    numInstancias = 3;
  }

  for (int i = 0, j = 0; i < numInstancias; i++, j++) {
    if (j < 5) {
      this->createPlataforma(vPlataformas[j].x, vPlataformas[j].y);
    }
    this->createEspinho(vEspinhos[j].x, vEspinhos[j].y);
    this->createCeifador(56+((rand()%9)*16), 248);
    this->createGhoul(168+((rand()%9)*16), 152);
  }
  
  this->pushEntidades();
}

void Ruina::executar() { this->lista->executar(); }

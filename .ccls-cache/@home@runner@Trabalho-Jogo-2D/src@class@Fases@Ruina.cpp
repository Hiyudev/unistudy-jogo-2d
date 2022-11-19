#include "Ruina.hpp"
#include <SFML/Graphics.hpp>

using namespace Fases;

Ruina::Ruina() : Fase() { srand(time(NULL)); }

Ruina::~Ruina() {}

void Ruina::createMap() {
  this->createBorda(0);

  // Plataformas
  for (int i = 16; i < 128; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i + 8, 56)));
  }

  for (int i = 16; i < 184; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i + 8, 104)));
  }

  for (int i = 192; i < 392; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i + 8, 88)));
  }

  for (int i = 464; i > 96; i -= 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i - 8, 168)));
  }

  for (int i = 16; i < 224; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 264)));
  }

  
}

void Ruina::generate() {
  this->createMap();
  this->createObstaculos(1);
  this->createObstaculos(2);
  this->createInimigos(3);
  this->createInimigos(5);
}

void Ruina::executar() { this->lista->executar(); }

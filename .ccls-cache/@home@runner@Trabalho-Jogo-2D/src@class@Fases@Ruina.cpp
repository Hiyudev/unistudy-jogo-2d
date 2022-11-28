#include "Ruina.hpp"
#include "../Projetil/Projetil.hpp"
#include <SFML/Graphics.hpp>

using namespace Fases;

Ruina::Ruina() : Fase() { }

Ruina::~Ruina() {}

void Ruina::createMap() {
  this->insertBorda(0);

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

  for (int i = 304; i > 248; i -= 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i - 8, 168)));
  }

  for (int i = 16; i < 132; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 264)));
  }
}

void Ruina::generate() {
  srand(time(NULL));
  this->createMap();

  sf::Vector2f vPlataformas[6] = {
      {328, 104}, {424, 104}, {184, 168}, {56, 200}, {264, 248}, {392, 280}};
  
  sf::Vector2f vEspinhos[6] = { {312, 168}, {328, 168}, {40, 248}, {152, 296},
                              {312, 296}, {328, 296}};

  sf::Vector2f vInimigos[5] = { {216, 72}, {408, 152}, {184, 152}, {216, 264}, {376, 264}};

  int instanciasObst = 3 + rand() % 4; 
  int instanciasIni = 3 + rand()%3;
  
  for (int i = 0; i < instanciasObst; i++) {
    if (i < 6) {
      this->insertPlataforma(vPlataformas[i].x, vPlataformas[i].y);
      this->insertEspinho(vEspinhos[i].x, vEspinhos[i].y);
    }
  }
  for(int j = 0; j < instanciasIni; j++){
    this->insertGhoul(vInimigos[j].x, vInimigos[j].y);
    this->insertCeifador(vInimigos[j].x + 16, vInimigos[j].y);
  }
  this->createEntidades();
}

void Ruina::executar() { this->lista->executar();  }

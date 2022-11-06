#include "FaseUm.hpp"
#include "../Bloco/Bloco.hpp"
#include "map"
#include <SFML/Graphics.hpp>

using namespace Entidades::Obstaculos;
using namespace Fases;

FaseUm::FaseUm() : Fase() {
  // Gera todas as paredes da janela
  // Todos de cima
  for (int i = 0; i < 480; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 8)));
  }

  // Todos de baixo
  for (int i = 0; i < 480; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 312)));
  }

  // Todos da esquerda
  for (int i = 16; i < 304; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8, 8 + i)));
  }

  // Todos da direita
  for (int i = 16; i < 304; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(472, 8 + i)));
  }

  // Plataforma
  for (int i = 16; i < 400; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 120)));
  }

	for (int i = 400; i > 16; i -= 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 248)));
  }

  this->generate();
};

FaseUm::~FaseUm(){};

void FaseUm::executar() {
  this->lista.executar();
  this->lista.draw();
};

void FaseUm::generate() {
  std::multimap<int, sf::Vector2f>::iterator it;

  for (it = this->map.begin(); it != this->map.end(); it++) {
    int type = it->first;
    sf::Vector2f pos = it->second;

    switch (type) {
    case 0:
      Bloco *bloco = new Bloco(pos);
      Entidade *castedBloco = static_cast<Entidade *>(bloco);
      this->lista.push(castedBloco);
      this->collisionManager->pushObstaculo(castedBloco);
      break;
    }
  }
};

void FaseUm::gerenciar_colisoes(){};
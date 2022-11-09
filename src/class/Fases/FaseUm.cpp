#include "FaseUm.hpp"
#include "../Bloco/Bloco.hpp"
#include "../Caixa/Caixa.hpp"
#include "../Morcego/Morcego.hpp"
#include "map"
#include <SFML/Graphics.hpp>
#include <cstdlib>

using namespace Entidades::Obstaculos;
using namespace Fases;

FaseUm::FaseUm() : Fase() {
  srand(time(NULL));
  this->generate();
};

FaseUm::~FaseUm(){};

void FaseUm::executar() {
  this->lista.executar();
  this->lista.draw();
};

void FaseUm::generate() {
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

  for (int i = 448; i > 80; i -= 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 200)));
  }

  // Gera obstaculos
  // Maximo de 10 obstaculos
  int quantity = (rand() % 10) + 1;

  // Minimo de 3 obstaculos
  if (quantity < 3) {
    quantity = 3;
  }

  for (int i = 0; i < quantity; i++) {
    int local = rand() % 3;

    switch (local) {
    case 0: {
      int posX = 72 + rand() % 80;
      int posY = 104;
      this->map.insert(
          std::pair<int, sf::Vector2f>(1, sf::Vector2f(posX, posY)));
    } break;
    case 1: {
      int posX = 352 + rand() % 48;
      int posY = 104;
      this->map.insert(
          std::pair<int, sf::Vector2f>(1, sf::Vector2f(posX, posY)));
    } break;
    case 2: {
      int posX = 104 + rand() % 128;
      int posY = 184;
      this->map.insert(
          std::pair<int, sf::Vector2f>(1, sf::Vector2f(posX, posY)));
    } break;
    }
  }

  // Gera inimigos (exceto o chefão)
  for (int j = 0; j < quantity; j++) {
    int local = rand() % 2;

    switch (local) {
    case 0: {
      int posX = 200 + rand() % 112;
      int posY = 104;
      this->map.insert(
          std::pair<int, sf::Vector2f>(3, sf::Vector2f(posX, posY)));
    } break;
    case 1: {
      int posX = 248 + rand() % 114;
      int posY = 184;
      this->map.insert(
          std::pair<int, sf::Vector2f>(3, sf::Vector2f(posX, posY)));
    } break;
    }
  }

  std::multimap<int, sf::Vector2f>::iterator it;

  for (it = this->map.begin(); it != this->map.end(); it++) {
    int type = it->first;
    sf::Vector2f pos = it->second;

    switch (type) {
    case 0: {
      Bloco *bloco = new Bloco(pos);
      Entidade *castedBloco = static_cast<Entidade *>(bloco);
      this->lista.push(castedBloco);
      this->collisionManager->pushObstaculo(castedBloco);
    } break;
    case 1: {
      Caixa *caixa = new Caixa(pos);
      Entidade *castedCaixa = static_cast<Entidade *>(caixa);
      this->lista.push(castedCaixa);
      this->collisionManager->pushObstaculo(castedCaixa);
    } break;
    case 3: {
      Morcego *morcego = new Morcego(pos);
      Entidade *castedMorcego = static_cast<Entidade *>(morcego);
      this->lista.push(castedMorcego);
      this->collisionManager->pushInimigo(castedMorcego);
    } break;
    }
  }
};

void FaseUm::gerenciar_colisoes(){};
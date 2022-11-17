#include "Ruina.hpp"
#include "../Bloco/Bloco.hpp"
#include "../Caixa/Caixa.hpp"
#include "../Ceifador/Ceifador.hpp"
#include "../Espinho/Espinho.hpp"
#include "../Ghoul/Ghoul.hpp"
#include <SFML/Graphics.hpp>

using namespace Fases;
using namespace Entidades::Obstaculos;

Ruina::Ruina() : Fase() { srand(time(NULL)); }

Ruina::~Ruina() {}

void Ruina::generate() {
  for (int i = 0; i < 480; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 8)));
  }

  for (int i = 0; i < 480; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 312)));
  }

  for (int i = 0; i < 304; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8, 8 + i)));
  }

  for (int i = 0; i < 304; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(472, 8 + i)));
  }

  // Plataformas
  for (int i = 16; i < 128; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i + 8, 56)));
  }

  for (int i = 16; i < 184; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i + 8, 104)));
  }

  this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(200, 88)));

  for (int i = 208; i < 408; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i + 8, 72)));
  }

  for (int i = 464; i > 96; i -= 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(i - 8, 168)));
  }

  for (int i = 16; i < 224; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 264)));
  }

  for (int i = 256; i < 480; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(0, sf::Vector2f(8 + i, 264)));
  }

  // Quantidades de instancias
  int qtd = (rand() % 10) + 1;
  if (qtd < 3) {
    qtd = 3;
  }

  for (int i = 0; i < qtd; i++) {
    int local = rand() % 2;

    switch (local) {
    case 0: {
      int posX = 120 + ((rand() % 5) * 16);
      int posY = 152;
      this->map.insert(
          std::pair<int, sf::Vector2f>(1, sf::Vector2f(posX, posY)));
    } break;
    case 1: {
      int posX = 128 + ((rand() % 7) * 16);
      int posY = 248;
      this->map.insert(
          std::pair<int, sf::Vector2f>(2, sf::Vector2f(posX, posY)));
    } break;
    }
  }

  for (int j = 0; j < qtd; j++) {
    int local = rand() % 2;

    switch (local) {
    case 0: {
      int posX = 120 + rand() % 112;
      int posY = 232;
      this->map.insert(
          std::pair<int, sf::Vector2f>(3, sf::Vector2f(posX, posY)));
    } break;
    case 1: {
      int posX = 248 + rand() % 114;
      int posY = 104;
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
      this->lista->push(castedBloco);
      this->collisionManager->pushObstaculo(castedBloco);
    } break;

    case 1: {
      Caixa *caixa = new Caixa(pos);
      Entidade *castedCaixa = static_cast<Entidade *>(caixa);
      this->lista->push(castedCaixa);
      this->collisionManager->pushObstaculo(castedCaixa);
    } break;

    case 2: {
      Espinho *espinho = new Espinho(pos);
      Entidade *castedEspinho = static_cast<Entidade *>(espinho);
      this->lista->push(castedEspinho);
      this->collisionManager->pushObstaculo(castedEspinho);
    } break;

    case 3: {
      int patrolTiming = rand() % 10;
      if (patrolTiming < 3) {
        patrolTiming = 3;
      }

      int rng = rand() % 2;

      if (rng == 0) {
        Ghoul *ghoul = new Ghoul(pos, patrolTiming);
        Entidade *castedGhoul = static_cast<Entidade *>(ghoul);
        this->lista->push(castedGhoul);
        this->collisionManager->pushInimigo(castedGhoul);
      } else {
        Ceifador *ceifador = new Ceifador(pos, patrolTiming);
        Entidade *castedCeifador = static_cast<Entidade *>(ceifador);
        this->lista->push(castedCeifador);
        this->collisionManager->pushInimigo(castedCeifador);
      }
    }
    }
  }
}

void Ruina::executar() { this->lista->executar(); }

#include "Fase.hpp"
#include "../../manager/CollisionManager.hpp"
#include "../Bloco/Bloco.hpp"
#include "../Ceifador/Ceifador.hpp"
#include "../Ente/Ente.hpp"
#include "../Espinho/Espinho.hpp"
#include "../Ghoul/Ghoul.hpp"
#include "../Jogador/Jogador.hpp"
#include "../Morcego/Morcego.hpp"
#include "../Plataforma/Plataforma.hpp"

using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Fases;
using namespace Entidades::Obstaculos;


Fase::Fase() : Ente() {
  this->lista = new ListaEntidades();
  this->collisionManager = CollisionManager::getInstance();
  srand(time(NULL));
}

Fase::~Fase() {
  this->collisionManager->clear();
  if(this->lista != NULL)
    delete this->lista;
};

void Fase::insertPlayer(Entidade *player) { this->lista->push(player); }

void Fase::insertBorda(int mapKey) {
  for (int i = 0; i < 480; i += 16) {
    this->map.insert(
        std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(8 + i, 8)));
  }

  for (int i = 0; i < 480; i += 16) {
    this->map.insert(
        std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(8 + i, 312)));
  }

  for (int i = 0; i < 304; i += 16) {
    this->map.insert(
        std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(8, 8 + i)));
  }

  for (int i = 0; i < 304; i += 16) {
    this->map.insert(
        std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(472, 8 + i)));
  }
}

void Fase::insertPlataforma(int posX, int posY) {
  this->map.insert(std::pair<int, sf::Vector2f>(1, sf::Vector2f(posX, posY)));
}

void Fase::insertEspinho(int posX, int posY) {
  this->map.insert(std::pair<int, sf::Vector2f>(2, sf::Vector2f(posX, posY)));
}

void Fase::insertMorcego(int posX, int posY) {
  this->map.insert(std::pair<int, sf::Vector2f>(4, sf::Vector2f(posX, posY)));
}

void Fase::insertGhoul(int posX, int posY) {
  this->map.insert(std::pair<int, sf::Vector2f>(3, sf::Vector2f(posX, posY)));

}

void Fase::insertCeifador(int posX, int posY) {
  this->map.insert(std::pair<int, sf::Vector2f>(5, sf::Vector2f(posX, posY)));

}

void Fase::createEntidades() {
  std::multimap<int, sf::Vector2f>::iterator it;

  for (it = this->map.begin(); it != this->map.end(); it++) {

    int patrolTiming = rand() % 10;
    if (patrolTiming < 3) {
      patrolTiming = 3;
    }

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
      Plataforma *plataforma = new Plataforma(pos);
      Entidade *castedPlataforma = static_cast<Entidade *>(plataforma);
      this->lista->push(castedPlataforma);
      this->collisionManager->pushObstaculo(castedPlataforma);
    } break;
    case 2: {
      Espinho *espinho = new Espinho(pos);
      Entidade *castedEspinho = static_cast<Entidade *>(espinho);
      this->lista->push(castedEspinho);
      this->collisionManager->pushObstaculo(castedEspinho);
    } break;
    case 3: {
      Ghoul *ghoul = new Ghoul(pos, patrolTiming);
      Entidade *castedGhoul = static_cast<Entidade *>(ghoul);
      this->lista->push(castedGhoul);
      this->collisionManager->pushInimigo(castedGhoul);
    } break;
    case 4: {
      Morcego *morcego = new Morcego(pos, patrolTiming);
      Entidade *castedMorcego = static_cast<Entidade *>(morcego);
      this->lista->push(castedMorcego);
      this->collisionManager->pushInimigo(castedMorcego);
    } break;
    case 5: {
      Ceifador *ceifador = new Ceifador(pos, patrolTiming);
      Entidade *castedCeifador = static_cast<Entidade *>(ceifador);
      this->lista->push(castedCeifador);
      this->collisionManager->pushInimigo(castedCeifador);
      Projetil *projetil = new Projetil(pos, true);
      ceifador->setProjetil(projetil);
      this->lista->push(static_cast<Entidade*>(projetil));
      this->collisionManager->pushProjetil(static_cast<Entidade*>(projetil));
    }
    }
  }
}
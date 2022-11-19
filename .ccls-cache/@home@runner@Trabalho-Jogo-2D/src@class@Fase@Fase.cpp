#include "Fase.hpp"
#include "../../manager/CollisionManager.hpp"
#include "../Ente/Ente.hpp"
#include "../Jogador/Jogador.hpp"
#include "../Ghoul/Ghoul.hpp"
#include "../Morcego/Morcego.hpp"
#include "../Bloco/Bloco.hpp"
#include "../Plataforma/Plataforma.hpp"
#include "../Espinho/Espinho.hpp"
#include "../Ceifador/Ceifador.hpp"

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
  int length = this->lista->getLength();
  for (int i = length - 1; i >= 0; i--) {
    Entidade *entidade = this->lista->getAt(i);
    delete entidade;
    this->lista->pop();
  }

  this->collisionManager->clear();

  delete this->lista;
};

void Fase::insertEntidade(Entidade *entidade) { this->lista->push(entidade); }

void Fase::createBorda(int mapKey){
  for (int i = 0; i < 480; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(8 + i, 8)));
  }

  for (int i = 0; i < 480; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(8 + i, 312)));
  }

  for (int i = 0; i < 304; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(8, 8 + i)));
  }

  for (int i = 0; i < 304; i += 16) {
    this->map.insert(std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(472, 8 + i)));
  }
}

void Fase::createInimigos(int mapKey){
  int qtd = rand() % 4+1;
  if(qtd < 2) { qtd = 2; }  
  
  int local = rand() % 2;
  
  for (int j = 0; j < qtd; j++) {
    int local = rand() % 2;

    switch (local) {
    case 0: {
      int posX = 120 + rand() % 112;
      int posY = 232;
      this->map.insert(
          std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(posX, posY)));
    } break;
    case 1: {
      int posX = 248 + rand() % 114;
      int posY = 104;
      this->map.insert(
          std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(posX, posY)));
    } break;
    }
  }
  
  std::multimap<int, sf::Vector2f>::iterator it;

  for(it = this->map.begin(); it != this->map.end(); it++){
    int type = it->first;
    sf::Vector2f pos = it->second;
    
    int patrolTiming = rand()%10;
    if(patrolTiming < 3){
      patrolTiming = 3;
    }

    switch(type) {
    case 3:{
      Ghoul *ghoul = new Ghoul(pos, patrolTiming);
      Entidade *castedGhoul = static_cast<Entidade *>(ghoul);
      this->lista->push(castedGhoul);
      this->collisionManager->pushInimigo(castedGhoul);
    }break;
    case 4:{
      Morcego *morcego = new Morcego(pos, patrolTiming);
      Entidade *castedMorcego = static_cast<Entidade *>(morcego);
      this->lista->push(castedMorcego);
      this->collisionManager->pushInimigo(castedMorcego);
    }break;
    case 5:{
      Ceifador *ceifador = new Ceifador(pos, patrolTiming);
      Entidade *castedCeifador = static_cast<Entidade *>(ceifador);
      this->lista->push(castedCeifador);
      this->collisionManager->pushInimigo(castedCeifador);
    }
    }
  }
  
}

void Fase::createObstaculos(int mapKey)
{
  int qtd = rand()%5 + 1;

  int local = rand() % 2;
  
  for (int i = 0; i < qtd; i++) {
    int local = rand() % 2;

    switch (local) {
    case 0: {
      int posX = 120 + (rand()%5)*16;
      int posY = 152;
      this->map.insert(
          std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(posX, posY)));
    } break;
    case 1: {
      int posX = 128 + (rand()%7)*16;
      int posY = 248;
      this->map.insert(
          std::pair<int, sf::Vector2f>(mapKey, sf::Vector2f(posX, posY)));
    } break;
    }
  }
  
  std::multimap<int, sf::Vector2f>::iterator it;

  for(it = this->map.begin(); it != this->map.end(); it++){
    int type = it->first;
    sf::Vector2f pos = it->second;
    
    switch(type){
    case 0: {
      Bloco *bloco = new Bloco(pos);
      Entidade *castedBloco = static_cast<Entidade*>(bloco);
      this->lista->push(castedBloco);
      this->collisionManager->pushObstaculo(castedBloco);
    } break;
    case 1:{
      Plataforma *plataforma = new Plataforma(pos);
      Entidade *castedPlataforma = static_cast<Entidade*>(plataforma);
      this->lista->push(castedPlataforma);
      this->collisionManager->pushObstaculo(castedPlataforma);
    } break;
    case 2:{
      Espinho *espinho = new Espinho(pos);  
      Entidade *castedEspinho = static_cast<Entidade*>(espinho);
      this->lista->push(castedEspinho);
      this->collisionManager->pushObstaculo(castedEspinho);
    } break;
      
    }
  }
}
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

void Fase::createPlataforma(int posX, int posY){
  this->map.insert(std::pair<int, sf::Vector2f>(1, sf::Vector2f(posX, posY)));
}

void Fase::createEspinho(int posX, int posY){
  this->map.insert(std::pair<int, sf::Vector2f>(2, sf::Vector2f(posX, posY)));
}

void Fase::createGhoul(int posX, int posY){
  this->map.insert(std::pair<int, sf::Vector2f>(3, sf::Vector2f(posX, posY)));
}

void Fase::createMorcego(int posX, int posY){
  this->map.insert(std::pair<int, sf::Vector2f>(4, sf::Vector2f(posX, posY)));
}

void Fase::pushEntidades(){
  std::multimap<int, sf::Vector2f>::iterator it;
  
  int patrolTiming = rand()%10;
    if(patrolTiming < 3){
      patrolTiming = 3;
    }
  
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
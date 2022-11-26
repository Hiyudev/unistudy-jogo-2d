#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

#include <list>
#include <vector>

#include "../class/Entidade/Entidade.hpp"
#include "../class/Obstaculo/Obstaculo.hpp"
#include "../utils/Math.hpp"
#include "CollisionManager.hpp"

namespace Entidades {
class Entidade;
}

using namespace Utils;
using namespace Entidades;
using namespace Entidades::Obstaculos;
using namespace Gerenciadores;

CollisionManager::CollisionManager(){};

CollisionManager::~CollisionManager() {
  if (this->_manager != nullptr) {
    delete this->_manager;
  }
};

CollisionManager *CollisionManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == nullptr) {
    _manager = new CollisionManager();
  }

  return _manager;
};

bool CollisionManager::canMoveTo(sf::Vector2f position, sf::Vector2f direction,
                                 Entidade *entidade, bool isInimigo) {

  sf::Vector2f posAfterDirection = Math::v_sum(position, direction);
  sf::RectangleShape hitboxRectangle(sf::Vector2f(16, 16));
  hitboxRectangle.setOrigin(8, 8);
  hitboxRectangle.setPosition(posAfterDirection);

  sf::FloatRect hitbox = hitboxRectangle.getGlobalBounds();

  bool collideObstaculo =
      this->checkCollideObstaculo(hitbox, direction, entidade);
  
  if(isInimigo == false){
    bool collideInimigo = this->checkCollideInimigo(hitbox, direction, entidade);
    checkCollisionsProjetil(hitbox, direction, entidade);
    return ((!collideObstaculo) && (!collideInimigo));
  }
  else{
    return (!collideObstaculo);
  }
}

bool CollisionManager::checkCollideObstaculo(sf::FloatRect hitbox,
                                             sf::Vector2f direction,
                                             Entidade *entidade) {

  std::vector<Entidade *>::iterator obstaculosIt;

  bool collideObstaculo = false;

  for (obstaculosIt = obstaculosList.begin();
       obstaculosIt != obstaculosList.end(); obstaculosIt++) {
    Entidade *obstaculo = *obstaculosIt;
    Obstaculo *castedObstaculo = static_cast<Obstaculo *>(obstaculo);

    sf::Sprite *sprite = obstaculo->getSprite();

    sf::FloatRect obstaculoHitbox = sprite->getGlobalBounds();

    bool collide = hitbox.intersects(obstaculoHitbox);

    if (collide) {
      collideObstaculo = true;

      if (entidade != NULL) {
        entidade->receive(obstaculo);
      }
    }
  }

  return collideObstaculo;
}

bool CollisionManager::checkCollideInimigo(sf::FloatRect hitbox,
                                           sf::Vector2f direction,
                                           Entidade *entidade) {

  std::list<Entidade *>::iterator inimigosIt;

  bool collideInimigo = false;
  
  for (inimigosIt = inimigosList.begin(); inimigosIt != inimigosList.end();
       inimigosIt++) {
    Entidade *inimigo = *inimigosIt;

    if(inimigo->getAtivo() == false)
      continue;
         
    sf::Sprite *sprite = inimigo->getSprite();

    sf::FloatRect inimigoHitbox = sprite->getGlobalBounds();
   
    bool collide = hitbox.intersects(inimigoHitbox);

    if (collide) {
      collideInimigo = true;

      if (entidade != NULL) {
        entidade->receive(inimigo);
        if(hitbox.top + hitbox.height -1 < inimigoHitbox.height)
        std::cout << hitbox.top + hitbox.height << " " << inimigoHitbox.top << std::endl;
      }
    }  
         
    if(collide && (hitbox.top + hitbox.height - 1) < inimigoHitbox.top ){
      if(entidade != NULL){
        inimigo->receive(entidade);
        inimigo->setAtivo(false);
      }
    }
         
  }

  return collideInimigo;
}

void CollisionManager::checkCollisionsProjetil(sf::FloatRect hitbox,
                                            sf::Vector2f direction,
                                            Entidade *entidade) {
  std::vector<Entidade *>::iterator projetilIt;
  

  for (projetilIt = projeteisList.begin(); projetilIt != projeteisList.end();
       projetilIt++) {
    Entidade *projetil = *projetilIt;

    sf::Sprite *sprite = projetil->getSprite();

    sf::FloatRect projetilHitbox = sprite->getGlobalBounds();

    bool collide = hitbox.intersects(projetilHitbox);
      
    if (collide) {
      if (entidade != NULL) {
        entidade->receive(projetil);
        projetil->setAtivo(false);
      }
    }
  }
}

void CollisionManager::pushProjetil(Entidade *projetil) {
  this->projeteisList.push_back(projetil);
}

void CollisionManager::pushInimigo(Entidade *inimigo) {
  this->inimigosList.push_back(inimigo);
}

void CollisionManager::pushObstaculo(Entidade *obstaculo) {
  this->obstaculosList.push_back(obstaculo);
}

void CollisionManager::clear() {
  this->obstaculosList.clear();
  this->inimigosList.clear();
  this->projeteisList.clear();
}
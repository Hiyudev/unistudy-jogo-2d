#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

#include <list>
#include <vector>

#include "../class/Entidade/Entidade.hpp"
#include "../class/Obstaculo/Obstaculo.hpp"
#include "../class/Personagem/Personagem.hpp"
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
  std::cout << "CollisionManager deconstructor" << '\n';
};

CollisionManager *CollisionManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == nullptr) {
    _manager = new CollisionManager();
  }

  return _manager;
};

bool CollisionManager::canMoveTo(sf::Vector2f position, sf::Vector2f direction,
                                 Entidade *entidade, bool isPlayer) {

  sf::Vector2f posAfterDirection = Math::Vector::sum(position, direction);
  sf::RectangleShape hitboxRectangle(sf::Vector2f(16, 16));
  hitboxRectangle.setOrigin(8, 8);
  hitboxRectangle.setPosition(posAfterDirection);

  sf::FloatRect hitbox = hitboxRectangle.getGlobalBounds();

  bool collideObstaculo = this->checkCollideObstaculo(hitbox, entidade);

  if (isPlayer == true) {
    bool collideInimigo = this->checkCollideInimigo(hitbox, entidade);
    checkCollisionsProjetil(hitbox, entidade);
    return ((!collideObstaculo) && (!collideInimigo));
  } else {
    return (!collideObstaculo);
  }
}

bool CollisionManager::checkCollideObstaculo(sf::FloatRect hitbox,
                                             Entidade *entidade) {

  std::vector<Entidade *>::iterator obstaculosIt;

  bool collideObstaculo = false;

  for (obstaculosIt = obstaculosList.begin();
       obstaculosIt != obstaculosList.end(); obstaculosIt++) {
    Entidade *obstaculo = *obstaculosIt;

    sf::Sprite *sprite = obstaculo->getSprite();

    sf::FloatRect obstaculoHitbox = sprite->getGlobalBounds();

    bool collide = hitbox.intersects(obstaculoHitbox);

    if (collide) {
      collideObstaculo = true;
      Obstaculo *castedObstaculo = (Obstaculo *)obstaculo;

      if (entidade != nullptr && castedObstaculo->getDealsDamage() == true) {
        entidade->receive(obstaculo);
      }
    }
  }

  return collideObstaculo;
}

bool CollisionManager::checkCollideInimigo(sf::FloatRect hitbox,
                                           Entidade *player) {
  std::list<Entidade *>::iterator inimigosIt;
  bool collideInimigo = false;

  for (inimigosIt = inimigosList.begin(); inimigosIt != inimigosList.end();
       inimigosIt++) {
    Entidade *inimigo = *inimigosIt;

    if (inimigo->getAtivo() == false)
      continue;

    sf::Sprite *sprite = inimigo->getSprite();

    sf::FloatRect inimigoHitbox = sprite->getGlobalBounds();

    bool collide = hitbox.intersects(inimigoHitbox);

    if (collide && (hitbox.top + hitbox.height - 1) < inimigoHitbox.top) {
      if (player != nullptr) {
        inimigo->receive(player);
        inimigo->setAtivo(false);
      }
    } else if (collide) {
      collideInimigo = true;

      if (player != nullptr) {
        player->receive(inimigo);
      }
    }
  }

  return collideInimigo;
}

void CollisionManager::checkCollisionsProjetil(sf::FloatRect hitbox,
                                               Entidade *player) {
  std::vector<Entidade *>::iterator projetilIt;

  for (projetilIt = projeteisList.begin(); projetilIt != projeteisList.end();
       projetilIt++) {
    Entidade *projetil = *projetilIt;

    if (projetil->getAtivo() == false)
      continue;

    sf::Sprite *sprite = projetil->getSprite();

    sf::FloatRect projetilHitbox = sprite->getGlobalBounds();

    bool collide = hitbox.intersects(projetilHitbox);

    if (collide) {
      if (player != nullptr) {
        player->receive(projetil);
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
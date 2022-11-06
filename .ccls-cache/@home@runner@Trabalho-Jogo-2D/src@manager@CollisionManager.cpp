#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

#include <list>
#include <vector>

#include "../class/Entidade/Entidade.hpp"
#include "../utils/Math.hpp"
#include "CollisionManager.hpp"

using namespace Utils;
using namespace Entidades;
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

bool CollisionManager::canMoveTo(sf::Vector2f position,
                                 sf::Vector2f direction) {
  sf::Vector2f posAfterDirection = Math::v_sum(position, direction);
  sf::RectangleShape hitbox(sf::Vector2f(16, 16));
  hitbox.setOrigin(8, 8);
  hitbox.setPosition(posAfterDirection);

  sf::FloatRect hitboxRectangle = hitbox.getGlobalBounds();

  std::vector<Entidade *>::iterator obstaculosIt;

  bool canMove = true;

  for (obstaculosIt = obstaculosList.begin();
       obstaculosIt != obstaculosList.end(); obstaculosIt++) {
    Entidade *obstaculo = *obstaculosIt;
    sf::Sprite *sprite = obstaculo->getSprite();

    sf::FloatRect spriteRectangle = sprite->getGlobalBounds();

    bool collide = hitboxRectangle.intersects(spriteRectangle);

    if (collide) {
      canMove = false;
    }
  }

  return canMove;
}

void CollisionManager::pushInimigo(Entidade *inimigo) {
  this->inimigosList.push_back(inimigo);
}

void CollisionManager::pushObstaculo(Entidade *obstaculo) {
  this->obstaculosList.push_back(obstaculo);
}
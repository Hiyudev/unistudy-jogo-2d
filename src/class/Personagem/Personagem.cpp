#include "Personagem.hpp"
#include "../../manager/CollisionManager.hpp"
#include <SFML/Graphics.hpp>
using namespace Entidades::Personagens;

Personagem::Personagem(sf::Vector2f pos, int health, sf::Vector2f vel)
    : Entidade(pos) {
  this->health = health;
  this->velocity = vel;

  this->isJumping = false;
  this->isTouchingGround = false;
  this->isPlayer = false;

  this->collisionManager = CollisionManager::getInstance();
};

Personagem::~Personagem(){};

const int Personagem::getHealth() { return this->health; }

void Personagem::operator--() { this->health--; };

bool Personagem::canMove(sf::Vector2f direction) {
  bool canMove = this->collisionManager->canMoveTo(this->pos, direction);

  return canMove;
}

bool Personagem::canMove(sf::Vector2f direction, bool *takeDamage) {
  bool canMove =
      this->collisionManager->canMoveTo(this->pos, direction, takeDamage);

  return canMove;
}

void Personagem::move(sf::Vector2f direction) {
  sf::Vector2f axisX(direction.x, 0);
  sf::Vector2f axisY(0, direction.y);
  sf::Vector2f axisGroundChecker(0, 1);

  // Verifica se está pisando no chão
  this->isTouchingGround = !(this->canMove(axisGroundChecker));

  // Verifica a colisão
  // No Y
  bool canMoveOnY = this->canMove(axisY);
  if (canMoveOnY == false) {
    direction.y = 0;
  }

  // No X
  bool canMoveOnX = this->canMove(axisX);
  if (canMoveOnX == false) {
    direction.x = 0;
  }

  // Caso esteja indo para direita, coloca o sprite do personagem para a direita
  if (direction.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (direction.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }

  this->sprite->move(direction);
  this->pos = this->sprite->getPosition();
}

void Personagem::move(sf::Vector2f direction, bool *takeDamage) {
  sf::Vector2f axisX(direction.x, 0);
  sf::Vector2f axisY(0, direction.y);
  sf::Vector2f axisGroundChecker(0, 1);

  // Verifica se está pisando no chão
  this->isTouchingGround = !(this->canMove(axisGroundChecker, takeDamage));

  // Verifica a colisão
  // No Y
  bool canMoveOnY = this->canMove(axisY, takeDamage);
  if (canMoveOnY == false) {
    direction.y = 0;
  }

  // No X
  bool canMoveOnX = this->canMove(axisX, takeDamage);
  if (canMoveOnX == false) {
    direction.x = 0;
  }

  // Caso esteja indo para direita, coloca o sprite do personagem para a direita
  if (direction.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (direction.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }

  this->sprite->move(direction);
  this->pos = this->sprite->getPosition();
}

void Personagem::executar(){};
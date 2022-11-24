#include "Personagem.hpp"
#include "../../manager/CollisionManager.hpp"
#include <SFML/Graphics.hpp>
using namespace Entidades::Personagens;

Personagem::Personagem(sf::Vector2f pos, bool flutuante, int health,
                       sf::Vector2f vel)
    : Entidade(pos, flutuante) {
  this->health = health;
  this->velocity = vel;

  //this->isJumping = false;
  this->isTouchingGround = false;
  this->isPlayer = false;
};

Personagem::~Personagem(){};

const int Personagem::getHealth() { return this->health; }
void Personagem::setHealth(const int health) { this->health = health; }

void Personagem::operator--() { this->health--; };

bool Personagem::canMove(sf::Vector2f direction, Personagem *personagem) {
  if(personagem == NULL) { std::cout << "Personagem::canMove" << std::endl;}
  bool canMove =
      this->collisionManager->canMoveTo(this->position, direction, personagem, (!personagem->getIsPlayer()));

  return canMove;
}

void Personagem::tryMove(sf::Vector2f direction, Personagem *personagem) {
  sf::Vector2f axisX(direction.x, 0);
  sf::Vector2f axisY(0, direction.y);
  sf::Vector2f axisGroundChecker(0, 1);

  if(personagem == NULL ) { std::cout << "..." << std::endl;}

  // Verifica se está pisando no chão
  this->isTouchingGround = !(this->canMove(axisGroundChecker, personagem));

  // Verifica a colisão
  // No Y
  bool canMoveOnY = this->canMove(axisY, personagem);
  if (canMoveOnY == false) {
    direction.y = 0;
  }

  // No X
  bool canMoveOnX = this->canMove(axisX, personagem);
  if (canMoveOnX == false) {
    direction.x = 0;
  }

  // Caso esteja indo para direita, coloca o sprite do personagem para a direita
  if (direction.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (direction.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }

  this->moveTo(direction);
}

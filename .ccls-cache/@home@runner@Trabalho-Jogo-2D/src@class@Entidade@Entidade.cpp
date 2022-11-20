#include "Entidade.hpp"
#include "../../manager/CollisionManager.hpp"
#include "../../manager/SpriteManager.hpp"
#include "../../utils/Math.hpp"
#include <SFML/Graphics.hpp>

namespace Gerenciadores {
class CollisionManager;
}

using namespace Utils;
using namespace Gerenciadores;
using namespace Entidades;

// Constructor
Entidade::Entidade(sf::Vector2f pos, bool flutuante) : Ente() {
  this->spriteManager = SpriteManager::getInstance();
  this->sprite = NULL;

  this->collisionManager = CollisionManager::getInstance();

  this->flutuante = flutuante;

  this->position = pos;
}

// Deconstructor
Entidade::~Entidade() { this->sprite = NULL; };

// Getter
void Entidade::setSprite(sf::Sprite *sprite) {
  if (sprite == nullptr) {
    std::cout << "Erro ao tentar setar um sprite nulo." << '\n';
    return;
  }

  this->sprite = sprite;
  this->sprite->setPosition(this->position);
}
// Setter
sf::Sprite *Entidade::getSprite() { return this->sprite; };

void Entidade::moveTo(sf::Vector2f direction) {
  this->sprite->move(direction);
  this->position = this->sprite->getPosition();
}

void Entidade::gravity() {
  // Gravidade
  sf::Vector2f gravity(0, 0.5f);

  bool canFall = this->collisionManager->canMoveTo(this->position, gravity);

  if (canFall == true) {
    this->moveTo(gravity);
  }
}

void Entidade::voar() {
  // Voar
  sf::Vector2f voar(0, -0.5f);

  bool canFly = this->collisionManager->canMoveTo(this->position, voar);

  if (canFly == true) {
    this->moveTo(voar);
  }
}

void Entidade::draw() { this->graphicManager->draw(this->sprite); }

void Entidade::move() {}

Entidade *Entidade::clone() { return NULL; }

void Entidade::executar() {
  this->move();
  this->gravity();

  if (this->flutuante) {
    this->voar();
  }

  this->draw();
}

void Entidade::setPosition(const sf::Vector2f pos) { this->position = pos; }
sf::Vector2f Entidade::getPosition() const { return this->position; }
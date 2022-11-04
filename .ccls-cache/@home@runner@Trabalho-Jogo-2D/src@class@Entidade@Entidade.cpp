#include "Entidade.hpp"
#include "../../manager/SpriteManager.hpp"
#include <SFML/Graphics.hpp>

using namespace Gerenciadores;
using namespace Entidades;

Entidade::Entidade() : Ente() {
  this->pos = sf::Vector2f(0, 0);
  this->spriteManager = SpriteManager::getInstance();
  this->sprite = NULL;
};

Entidade::Entidade(sf::Vector2f pos) : Ente() {
  this->pos = pos;
  this->spriteManager = SpriteManager::getInstance();
  this->sprite = NULL;
}

Entidade::Entidade(int x, int y) : Ente() {
  this->pos = sf::Vector2f(x, y);
  this->spriteManager = SpriteManager::getInstance();
  this->sprite = NULL;
}

Entidade::~Entidade(){};

void Entidade::setSprite(sf::Sprite *sprite) {
  this->sprite = sprite;
  this->sprite->setPosition(this->pos);
}
sf::Sprite *Entidade::getSprite() { return this->sprite; };

void Entidade::executar(){};

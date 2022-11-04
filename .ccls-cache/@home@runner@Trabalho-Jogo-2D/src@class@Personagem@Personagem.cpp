#include "Personagem.hpp"
#include <SFML/Graphics.hpp>
using namespace Entidades::Personagens;

Personagem::Personagem(sf::Vector2f pos, int health, sf::Vector2f vel) : Entidade(pos) {
  this->health = health;
  this->velocity = vel;
};

Personagem::~Personagem(){};

const int Personagem::getHealth() { return this->health; }

void Personagem::operator--() { this->health--; };

void Personagem::move(sf::Vector2f direction) {
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
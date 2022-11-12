#include "Entidade.hpp"
#include "../../manager/SpriteManager.hpp"
#include <SFML/Graphics.hpp>

using namespace Gerenciadores;
using namespace Entidades;

Entidade::Entidade(sf::Vector2f pos = sf::Vector2f(0, 0)) : Ente() {
  this->pos = pos;
  this->sprite = NULL;
}

Entidade::~Entidade(){};

void Entidade::setSprite(sf::Sprite *sprite) {
  if (sprite == nullptr) {
    std::cout << "Erro ao tentar setar um sprite nulo." << '\n';
    return;
  }

  this->sprite = sprite;
  this->sprite->setPosition(this->pos);
}
sf::Sprite *Entidade::getSprite() { return this->sprite; };

void Entidade::executar(){};

#include "Ghoul.hpp"
#include <SFML/Graphics.hpp>

using namespace Entidades::Personagens;

Ghoul::Ghoul(sf::Vector2f position) : Inimigo(position, 3, 50.f) {
  this->setSprite(
      this->spriteManager->getSprite("assets/personagens/Ghoul.png"));
}

Ghoul::~Ghoul() {}

void Ghoul::move() {}

void Ghoul::executar() {}
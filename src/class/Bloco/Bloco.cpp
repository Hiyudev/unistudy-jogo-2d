#include "Bloco.hpp"
#include "../Obstaculo/Obstaculo.hpp"
#include <SFML/Graphics.hpp>

using namespace Entidades::Obstaculos;

Bloco::Bloco(sf::Vector2f position) : Obstaculo(position, false) {
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Bloco.png"));
};
Bloco::~Bloco(){};

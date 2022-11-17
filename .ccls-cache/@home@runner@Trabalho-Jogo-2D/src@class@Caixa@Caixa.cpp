#include "Caixa.hpp"
#include "../Obstaculo/Obstaculo.hpp"
#include <SFML/Graphics.hpp>

using namespace Entidades::Obstaculos;

Caixa::Caixa(sf::Vector2f position) : Obstaculo(position, false) {
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Caixa.png"));
};
Caixa::~Caixa(){}; 
#include "Espinho.hpp"
#include "../Obstaculo/Obstaculo.hpp"
#include <SFML/Graphics.hpp>

using namespace Entidades::Obstaculos;

Espinho::Espinho(sf::Vector2f position) : Obstaculo(position, true) {
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Espinho.png"));
};
Espinho::~Espinho(){};

void Espinho::executar() {}

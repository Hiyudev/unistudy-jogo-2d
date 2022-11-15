#include "Obstaculo.hpp"
#include <SFML/Graphics.hpp>
using namespace Entidades::Obstaculos;

Obstaculo::Obstaculo(sf::Vector2f position, bool dealsDamage = false)
    : Entidade(position) {
  this->dealsDamage = dealsDamage;
};

Obstaculo::~Obstaculo(){};

bool Obstaculo::getDealsDamage() { return this->dealsDamage; }

void Obstaculo::executar(){};

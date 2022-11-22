#include "Projetil.hpp"
#include "../../utils/Math.hpp"
#include <SFML/Graphics.hpp>

using namespace Utils;
using namespace Entidades;

Projetil::Projetil(sf::Vector2f pos) : Entidade(pos) {
  this->setSprite(
      this->spriteManager->getSprite("assets/projetil/Projetil.png"));

}

Projetil::~Projetil() {}

void Projetil::move(){
  this->velocity = sf::Vector2f(0.1f, 0.1f);

}
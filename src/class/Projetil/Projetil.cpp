#include "Projetil.hpp"
#include "../../utils/Math.hpp"
#include "../Jogador/Jogador.hpp"
#include <SFML/Graphics.hpp>

using namespace Utils;
using namespace Entidades;
using namespace Entidades::Personagens;

Projetil::Projetil(sf::Vector2f pos, bool flutuante) : Entidade(pos, flutuante) {
  this->setSprite(
      this->spriteManager->getSprite("assets/projetil/Projetil.png"));

  this->sprite->setScale(0.5, 0.5);
}

Projetil::~Projetil() {}

void Projetil::move(){
  sf::Vector2f distance;

}

void Projetil::draw(){
  this->graphicManager->draw(this->sprite);
}


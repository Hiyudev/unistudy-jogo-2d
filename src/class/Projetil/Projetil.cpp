#include "Projetil.hpp"
#include "../../utils/Math.hpp"
#include <SFML/Graphics.hpp>

using namespace Utils;
using namespace Entidades;

Projetil::Projetil(sf::Vector2f pos, Ceifador *pCeifador) : Entidade(pos) {
  this->setSprite(
      this->spriteManager->getSprite("assets/projetil/Projetil.png"));

  this->pCeifador = pCeifador; 

}

Projetil::~Projetil() {}

void Projetil::move(){
  this->velocity = sf::Vector2f(0.1f, 0.1f);

}
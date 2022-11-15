#include "Projetil.hpp" 
#include <SFML/Graphics.hpp>

using namespace Entidades;

Projetil::Projetil(sf::Vector2f pos) : Entidade(pos) 
{
  this->setSprite(this->spriteManager->getSprite("assets/projetil/Projetil.png"));
}

Projetil::~Projetil(){
  
}
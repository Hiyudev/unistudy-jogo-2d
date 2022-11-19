#include "Caixa.hpp"
#include "../Obstaculo/Obstaculo.hpp"
#include <SFML/Graphics.hpp>

using namespace Entidades::Obstaculos;

Caixa::Caixa(sf::Vector2f position) : Obstaculo(position, false) {
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Caixa.png"));

  srand((unsigned)time(NULL));
  this->randomWidth();
};

Caixa::Caixa(sf::Vector2f position, float width): Obstaculo(position, false){
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Caixa,png"));

  this->sprite->setScale(width, 1.0);
  this->sprite->setOrigin(width*8, 8);
}

Caixa::~Caixa(){}; 

void Caixa::randomWidth(){
  int rdn = rand()%10;
  float width = 1.0 + 1/(10/(float)rdn);
  this->sprite->setScale(width, 1.0);
  this->sprite->setOrigin(8*width, 8);
}
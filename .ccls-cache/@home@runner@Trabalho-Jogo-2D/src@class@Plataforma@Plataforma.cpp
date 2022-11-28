#include "Plataforma.hpp"
#include "../Obstaculo/Obstaculo.hpp"
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace Entidades::Obstaculos;

Plataforma::Plataforma(sf::Vector2f position) : Obstaculo(position, false) {
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Plataforma.png"));

  srand((unsigned)time(NULL));
  this->randomWidth();
};

Plataforma::Plataforma(sf::Vector2f position, float width): Obstaculo(position, false){
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Plataforma.png"));

  this->sprite->setScale(width, 1.0);
  this->sprite->setOrigin(width*8, 8);
}

Plataforma::~Plataforma(){}; 

void Plataforma::randomWidth(){
  int rdn = rand()%10;
  float width = 1 + 1/(10/(float)rdn);
  this->sprite->setScale(width, 1.0);
  this->sprite->setOrigin(8*width, 8);
}
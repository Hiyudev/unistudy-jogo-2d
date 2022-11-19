#include "Espinho.hpp"
#include "../Obstaculo/Obstaculo.hpp"
#include <stdlib.h>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace Entidades::Obstaculos;

Espinho::Espinho(sf::Vector2f position) : Obstaculo(position, true) {
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Espinho.png"));

  srand( (unsigned)time(NULL) );
  this->randomHeight();
};

Espinho::Espinho(sf::Vector2f position, float height):
Obstaculo(position, true){
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Espinho.png"));

  this->sprite->setScale(1.f, height);
  this->sprite->setOrigin(8, 8*height);
}

Espinho::~Espinho(){};

void Espinho::randomHeight(){
  int rdn = rand()%10+1;
  float height = 0.5 + 1/(10/(float)rdn);
  this->sprite->setScale(1.f, height);
  this->sprite->setOrigin(8, 8*height);
}

#include "Espinho.hpp"
#include "../Obstaculo/Obstaculo.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

using namespace Entidades::Personagens;
using namespace Entidades::Obstaculos;

Espinho::Espinho(sf::Vector2f position) : Obstaculo(position, true) {
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Espinho.png"));

  srand((unsigned)time(NULL));
  this->randomHeight();
};

Espinho::Espinho(sf::Vector2f position, float height)
    : Obstaculo(position, true) {
  this->setSprite(spriteManager->getSprite("assets/obstaculo/Espinho.png"));

  this->sprite->setScale(1.f, height);
  this->sprite->setOrigin(8, 8 * height);
}

Espinho::~Espinho(){};

void Espinho::randomHeight() {
  int rdn = rand() % 10 + 1;
  float height = 0.5 + 1 / (10 / (float)rdn);
  this->sprite->setScale(1.f, height);
  this->sprite->setOrigin(8, 8 * height);
}

void Espinho::deal(Entidade *entidade) {
  try {
    Personagem *personagem = (Personagem *)entidade;

    if (personagem == NULL) {
      throw 0;
    }

    personagem->operator--();
  } catch (int errID) {
    if (errID == 0) {
      std::cout << "Casting failed" << '\n';
    }
  }
}

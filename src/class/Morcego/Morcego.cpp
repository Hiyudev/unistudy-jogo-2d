#include "Morcego.hpp"
#include "../../utils/Math.hpp"
#include "../Inimigo/Inimigo.hpp"
#include "../Jogador/Jogador.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace Utils;
using namespace Entidades::Personagens;

Morcego::Morcego(sf::Vector2f position) : Inimigo(position, 3, 50.0f) {
  this->setSprite(
      this->spriteManager->getSprite("assets/personagens/Morcego.png"));
};
Morcego::~Morcego(){};

void Morcego::patrol() {
  if (this->clock.getElapsedTime().asSeconds() >
      this->patrolDirectionTimerInSeconds) {

    sf::Vector2f dir;
    int rng = rand() % 4;

    switch (rng) {
    case 0:
      dir.x = 1;
      break;
    case 1:
      dir.x = -1;
      break;
    case 2:
      dir.y = 1;
      break;
    case 3:
      dir.y = -1;
      break;
    }

    this->patrolDirection = dir;
    this->clock.restart();
  }
}

void Morcego::executar() {
  if (this->isPlayerNearby()) {
    sf::Vector2f distance = Math::v_distance(Jogador::position, this->pos);
    // Limita a distancia
    if (distance.x > 1) {
      distance.x = 1;
    } else if (distance.x < -1) {
      distance.x = -1;
    }

    if (distance.y > 1) {
      distance.y = 1;
    } else if (distance.y < -1) {
      distance.y = -1;
    }

    sf::Vector2f movement = Math::v_multi(distance, this->velocity);

    this->move(movement);
  } else {
    sf::Vector2f movement =
        Math::v_multi(this->patrolDirection, this->velocity);
    this->move(movement);
    this->patrol();
  }
}
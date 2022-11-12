#include "Morcego.hpp"
#include "../../utils/Math.hpp"
#include "../Inimigo/Inimigo.hpp"
#include "../Jogador/Jogador.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace Utils;
using namespace Entidades::Personagens;

Morcego::Morcego(sf::Vector2f position, int patrolTiming) : Inimigo(position, patrolTiming, 50.0f) {
  this->setSprite(
      this->spriteManager->getSprite("assets/personagens/Morcego.png"));
};
Morcego::~Morcego(){};

void Morcego::patrol() {
  if (this->clock.getElapsedTime().asSeconds() >
      this->patrolDirectionTimerInSeconds) {

    sf::Vector2f dir;
    int rngDirX = rand() % 2;
    int rngDirY = rand() % 2;

    switch (rngDirX) {
    case 0:
      dir.x = 1;
      break;
    case 1:
      dir.x = -1;
      break;
    }

		switch(rngDirY)
			{
			case 0:
				dir.y = 1;
				break;
			case 1:
				dir.y = -1;
				break;
			case 2:
				dir.y = 0;
				break;
			}

    this->patrolDirection = dir;
    this->clock.restart();
  }
}

void Morcego::executar() {
  if (this->isPlayerNearby()) {
    sf::Vector2f distance;
    sf::Vector2f playerOneDistance =
        Math::v_distance(Jogador::playerOnePosition, this->pos);

    if (Jogador::hasSecondPlayer) {
      sf::Vector2f playerTwoDistance =
          Math::v_distance(Jogador::playerTwoPosition, this->pos);

      float playerOneDistanceLength =
          Math::distance(this->pos, Jogador::playerOnePosition);
      float playerTwoDistanceLength =
          Math::distance(this->pos, Jogador::playerTwoPosition);

      if (playerOneDistanceLength < playerTwoDistanceLength) {
        distance = playerOneDistance;
      } else {
        distance = playerTwoDistance;
      }
    } else {
      distance = playerOneDistance;
    }

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
#include "Ghoul.hpp"
#include "../../utils/Math.hpp"
#include "../Inimigo/Inimigo.hpp"
#include "../Jogador/Jogador.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace Utils;
using namespace Entidades::Personagens;

Ghoul::Ghoul(sf::Vector2f position, int patrolTiming)
    : Inimigo(position, false, patrolTiming, 50.0f) {
  this->isHungry = rand() % 2 == 0;
  this->setSprite(
      this->spriteManager->getSprite("assets/personagens/Ghoul.png"));
};
Ghoul::~Ghoul(){};

void Ghoul::patrol() {
  if (this->clock.getElapsedTime().asSeconds() >
      this->patrolDirectionTimerInSeconds) {

    sf::Vector2f dir;
    int rngDirX = rand() % 2;

    switch (rngDirX) {
    case 0:
      dir.x = 1;
      break;
    case 1:
      dir.x = -1;
      break;
    }

    this->patrolDirection = dir;
    this->clock.restart();
  }
}

void Ghoul::move() {
  if (this->isPlayerNearby()) {
    sf::Vector2f distance;
    sf::Vector2f playerOneDistance =
        Math::Vector::distance(Jogador::playerOnePosition, this->position);

    if (Jogador::hasSecondPlayer) {
      sf::Vector2f playerTwoDistance =
          Math::Vector::distance(Jogador::playerTwoPosition, this->position);

      float playerOneDistanceLength =
          Math::distance(this->position, Jogador::playerOnePosition);
      float playerTwoDistanceLength =
          Math::distance(this->position, Jogador::playerTwoPosition);

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
    sf::Vector2f gravity(0, 0.5f);

    float rageTime = 1000;
    if (this->isHungry == true &&
        chasingDeltaTime.getElapsedTime().asMilliseconds() > rageTime) {
      this->velocity = sf::Vector2f(0.2f, 0.2f);
    }

    sf::Vector2f movement = Math::Vector::sum(
        Math::Vector::multi(distance, this->velocity), gravity);

    this->tryMove(movement, this);
  } else {
    if (isHungry == true) {
      this->chasingDeltaTime.restart();
    }
    this->velocity = sf::Vector2f(0.1f, 0.1f);
    sf::Vector2f gravity(0, 0.5f);
    sf::Vector2f movement = Math::Vector::sum(
        Math::Vector::multi(this->patrolDirection, this->velocity), gravity);
    this->tryMove(movement, this);
    this->patrol();
  }
}

void Ghoul::deal(Entidade *entidade) {
  try {
    Personagem *personagem = (Personagem *)entidade;

    if (personagem == NULL) {
      throw 0;
    }

    std::cout << "dano ghoul" << std::endl;
    for (int i = 0; i < 15; i++)
      personagem->operator--();
  } catch (int errID) {
    std::cout << "casting failed" << std::endl;
  }
}

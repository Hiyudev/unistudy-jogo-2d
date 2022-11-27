#include "Morcego.hpp"
#include "../../utils/Math.hpp"
#include "../Inimigo/Inimigo.hpp"
#include "../Jogador/Jogador.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace Utils;
using namespace Entidades::Personagens;

Morcego::Morcego(sf::Vector2f position, int patrolTiming)
    : Inimigo(position, true, patrolTiming, 50.0f) {
  this->setSprite(
      this->spriteManager->getSprite("assets/personagens/Morcego.png"));

  this->isVampiro = rand() % 2 == 0;

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

    switch (rngDirY) {
    case 0:
      dir.y = 1;
      break;
    case 1:
      dir.y = -1;
      break;
    }

    this->patrolDirection = dir;
    this->clock.restart();
  }
}

void Morcego::move() {
  if (this->isPlayerNearby() && this->isVampiro == true) {
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

    sf::Vector2f movement = Math::Vector::multi(distance, this->velocity);

    this->tryMove(movement, this);
  } else {
    sf::Vector2f movement =
        Math::Vector::multi(this->patrolDirection, this->velocity);
    this->tryMove(movement, this);
    this->patrol();
  }
}

void Morcego::deal(Entidade* entidade){
  try{
    Personagem *personagem = (Personagem*)entidade;

    if(personagem == NULL){
      throw 0;
    }

    for(int i=0; i < 10; i++)
      personagem->operator--();

    std::cout << "dano morcego" << std::endl;
  } catch (int errID){
    std::cout << "casting failed" << std::endl;
  }
}
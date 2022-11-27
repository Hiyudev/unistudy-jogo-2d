#include "Inimigo.hpp"
#include "../../utils/Math.hpp"
#include "../Jogador/Jogador.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>

using namespace Utils;
using namespace Entidades::Personagens;

Inimigo::Inimigo(sf::Vector2f position, bool flutuante,
                 int patrolDirectionTimerInSeconds = 2,
                 float playerDetectionRadius = 50.0f)
    : Personagem(sf::Vector2f(position), flutuante, 1,
                 sf::Vector2f(0.1f, 0.1f)) {
  this->patrolDirectionTimerInSeconds = patrolDirectionTimerInSeconds;
  this->playerDetectionRadius = playerDetectionRadius;
  this->isPlayer = false;
};
Inimigo::~Inimigo(){};

bool Inimigo::isPlayerNearby() {
  float playerOneDistance =
      Math::distance(this->position, Jogador::playerOnePosition);
  float playerTwoDistance =
      Math::distance(this->position, Jogador::playerTwoPosition);

  float distance = std::min(playerOneDistance, playerTwoDistance);

  return (distance < this->playerDetectionRadius);
}

void Inimigo::receive(Entidade *entidade) {
	entidade->deal(this);
}

void Inimigo::deal(Entidade *entidade) {
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

sf::Vector2f Inimigo::getPatrolDirection(){
  return this->patrolDirection;
}
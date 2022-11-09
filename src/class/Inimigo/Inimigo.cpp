#include "Inimigo.hpp"
#include "../../utils/Math.hpp"
#include "../Jogador/Jogador.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>

using namespace Utils;
using namespace Entidades::Personagens;

Inimigo::Inimigo(sf::Vector2f position, int patrolDirectionTimerInSeconds = 2,
                 float playerDetectionRadius = 50.0f)
    : Personagem(sf::Vector2f(position), 3, sf::Vector2f(0.1f, 0.1f)) {
  this->patrolDirectionTimerInSeconds = patrolDirectionTimerInSeconds;
  this->playerDetectionRadius = playerDetectionRadius;
};
Inimigo::~Inimigo(){};

bool Inimigo::isPlayerNearby() {
  float playerOneDistance = Math::distance(this->pos, Jogador::playerOnePosition);
	float playerTwoDistance = Math::distance(this->pos, Jogador::playerTwoPosition);

	float distance = std::min(playerOneDistance, playerTwoDistance);

  return (distance < this->playerDetectionRadius);
}

void Inimigo::patrol(){};
void Inimigo::executar(){};
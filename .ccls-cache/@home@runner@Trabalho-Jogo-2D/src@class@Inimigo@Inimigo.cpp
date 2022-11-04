#include "Inimigo.hpp"
#include "../../utils/Math.hpp"
#include "../Jogador/Jogador.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Utils;
using namespace Entidades::Personagens;

Inimigo::Inimigo(sf::Vector2f position, int patrolDirectionTimerInSeconds = 2,
                 float playerDetectionRadius = 50.0f)
    : Personagem(sf::Vector2f(position), 3, sf::Vector2f(0.01f, 0.01f)) {
  this->patrolDirectionTimerInSeconds = patrolDirectionTimerInSeconds;
  this->playerDetectionRadius = playerDetectionRadius;
};
Inimigo::~Inimigo(){};

bool Inimigo::isPlayerNearby() {
  float distance = Math::distance(this->pos, Jogador::position);

  return (distance < this->playerDetectionRadius);
}

void Inimigo::patrol(){};
void Inimigo::executar(){};
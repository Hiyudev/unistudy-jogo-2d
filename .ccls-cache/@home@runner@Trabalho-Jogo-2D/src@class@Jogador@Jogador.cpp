#include "Jogador.hpp"
#include "../../manager/KeyboardManager.hpp"
#include "../../utils/Math.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace Utils;
using namespace Gerenciadores;
using namespace Entidades::Personagens;

sf::Vector2f Jogador::position = sf::Vector2f(0, 0);

Jogador::Jogador(sf::Vector2f position, bool isSecondPlayer = false)
    : Personagem(position, 3, sf::Vector2f(0.1f, 0.1f)) {
  Jogador::position = position;
  this->keyboardManager = KeyboardManager::getInstance();
  this->setSprite(spriteManager->getSprite("assets/personagens/Jogador.png"));
  this->isSecondPlayer = isSecondPlayer;
};

Jogador::~Jogador(){};

bool Jogador::getIsSecondPlayer() { return this->isSecondPlayer; };

void Jogador::move(sf::Vector2f direction) {
  this->sprite->move(direction);
  this->pos = this->sprite->getPosition();
  Jogador::position = this->pos;
}

void Jogador::executar() {
  sf::Vector2f control;

  // Pega quais teclas estao sendo precionados em um formato de <Vector2f>
  if (isSecondPlayer == false) {
    control = this->keyboardManager->getJogadorUmControl();
  }

  sf::Vector2f movement = Math::v_multi(control, velocity);

  // Caso esteja indo para direita, coloca o sprite do jogador para a direita
  if (control.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (control.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }

  this->move(movement);
};
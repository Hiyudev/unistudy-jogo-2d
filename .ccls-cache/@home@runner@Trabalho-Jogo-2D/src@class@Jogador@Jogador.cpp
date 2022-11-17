#include "Jogador.hpp"
#include "../../manager/KeyboardManager.hpp"
#include "../../utils/Math.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace Utils;
using namespace Gerenciadores;
using namespace Entidades::Personagens;

bool Jogador::hasSecondPlayer = false;
sf::Vector2f Jogador::playerOnePosition = sf::Vector2f(0, 0);
sf::Vector2f Jogador::playerTwoPosition = sf::Vector2f(0, 0);

Jogador::Jogador(sf::Vector2f position, bool isSecondPlayer = false)
    : Personagem(position, false, 3, sf::Vector2f(0.3f, 0.3f)) {
  this->isPlayer = true;
  this->isSecondPlayer = isSecondPlayer;
  this->keyboardManager = KeyboardManager::getInstance();
  this->setSprite(spriteManager->getSprite("assets/personagens/Jogador.png"));

  if (isSecondPlayer) {
    this->hasSecondPlayer = true;
    Jogador::playerTwoPosition = position;
    this->getSprite()->setColor(sf::Color::Green);
  } else {
    Jogador::playerOnePosition = position;
    this->getSprite()->setColor(sf::Color::Red);
  }
};

Jogador::~Jogador() { delete this->keyboardManager; };

bool Jogador::getIsSecondPlayer() { return this->isSecondPlayer; };

void Jogador::move() {
  sf::Vector2f control;

  // Pega quais teclas estao sendo precionados em um formato de <Vector2f>
  if (isSecondPlayer == false) {
    control = this->keyboardManager->getJogadorUmControl();
  } else {
    control = this->keyboardManager->getJogadorDoisControl();
  }

  // Pulo
  // jumpTime está em milisegundos
  float jumpTime = 150;
  float jumpForce = 2;

  if (control.y == 1 && this->isJumping == false &&
      this->isTouchingGround == true) {
    this->isJumping = true;
    this->jumpDeltaTime.restart();
  }

  // Movimento
  sf::Vector2f movement = Math::v_multi(control, velocity);

  // Pulo
  if (isJumping) {
    movement = Math::v_sum(movement, sf::Vector2f(0, -jumpForce));

    if (this->jumpDeltaTime.getElapsedTime().asMilliseconds() > jumpTime) {
      isJumping = false;
    }
  }

  // Caso esteja indo para direita, coloca o sprite do jogador para a direita
  if (control.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (control.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }

  float iFramesTime = 500;
  bool takeDamage = false;
  if (tookDamage) {
    this->tryMove(movement);
  } else {
    this->tryMove(movement, &takeDamage);
  }

  if (takeDamage && (tookDamage == false)) {
    this->operator--();
    this->tookDamage = true;

    this->knockback(movement);
    this->invulnerableDeltaTime.restart();
  }

  if (tookDamage) {
    if (this->invulnerableDeltaTime.getElapsedTime().asMilliseconds() >
        iFramesTime) {
      tookDamage = false;
    }
  }

  if (isSecondPlayer) {
    Jogador::playerTwoPosition = this->position;
  } else {
    Jogador::playerOnePosition = this->position;
  }
};

void Jogador::knockback(sf::Vector2f direction) {
  sf::Vector2f invertedDirection = Math::v_invert(direction);

  sf::Vector2f knockbackForce;
  knockbackForce.x = direction.x == 0 ? (rand() % 3) - 1 : 0;
  knockbackForce.y = 0;

  sf::Vector2f knockbackDirection =
      Math::v_multi(Math::v_sum(invertedDirection, knockbackForce), 25);

  this->tryMove(knockbackDirection);

  if (knockbackDirection.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (knockbackDirection.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }
}
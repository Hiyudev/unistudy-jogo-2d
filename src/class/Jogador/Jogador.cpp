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
    : Personagem(position, 3, sf::Vector2f(0.3f, 0.3f)) {
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

  this->isSecondPlayer = isSecondPlayer;
};

Jogador::~Jogador() { delete this->keyboardManager; };

bool Jogador::getIsSecondPlayer() { return this->isSecondPlayer; };

void Jogador::executar() {
  sf::Vector2f control;

  // Pega quais teclas estao sendo precionados em um formato de <Vector2f>
  if (isSecondPlayer == false) {
    control = this->keyboardManager->getJogadorUmControl();
  } else {
    control = this->keyboardManager->getJogadorDoisControl();
  }

  // Jump
	// jumpTime está em milisegundos
	float jumpTime = 150;
  float jumpForce = 2;
	
  if (control.y == 1 && this->isJumping == false &&
      this->isTouchingGround == true) {
    this->isJumping = true;
		deltaTime.restart();
  }

  sf::Vector2f gravity(0, 0.5f);
  sf::Vector2f movement =
      Math::v_sum(Math::v_multi(control, velocity), gravity);

  if (isJumping) {
    movement = Math::v_sum(movement, sf::Vector2f(0, -jumpForce));

		if(deltaTime.getElapsedTime().asMilliseconds() > jumpTime) {
    	isJumping = false;
		}
  }

  // Caso esteja indo para direita, coloca o sprite do jogador para a direita
  if (control.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (control.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }

  this->move(movement);

  if (isSecondPlayer) {
    Jogador::playerTwoPosition = this->pos;
  } else {
    Jogador::playerOnePosition = this->pos;
  }
};
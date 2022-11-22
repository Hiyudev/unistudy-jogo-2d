#include "Jogador.hpp"
#include "../../manager/KeyboardManager.hpp"
#include "../../utils/Math.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace Utils;
using namespace Gerenciadores;
using namespace Entidades::Personagens;

bool Jogador::dead = false;
bool Jogador::hasSecondPlayer = false;
sf::Vector2f Jogador::playerOnePosition = sf::Vector2f(0, 0);
sf::Vector2f Jogador::playerTwoPosition = sf::Vector2f(0, 0);

Jogador::Jogador(sf::Vector2f position, bool isSecondPlayer = false)
    : Personagem(position, false, 100, sf::Vector2f(0.3f, 0.3f)) {
  this->isPlayer = true;
  this->isSecondPlayer = isSecondPlayer;
  this->keyboardManager = KeyboardManager::getInstance();
  this->setSprite(spriteManager->getSprite("assets/personagens/Jogador.png"));

  if (isSecondPlayer) {
    Jogador::hasSecondPlayer = true;
    Jogador::playerTwoPosition = position;
    this->getSprite()->setColor(sf::Color(55, 171, 151, 255));
  } else {
    Jogador::playerOnePosition = position;
    this->getSprite()->setColor(sf::Color(205, 82, 95, 255));
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
  float jumpForce = 3;

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

  float iFramesTime = 500;

  if (tookDamage) {
    if (this->invulnerableDeltaTime.getElapsedTime().asMilliseconds() >
        iFramesTime) {

      // Reseta a transparencia do efeito de piscada do player
      if (this->isSecondPlayer) {
        this->getSprite()->setColor(sf::Color(55, 171, 151, 255));
      } else {
        this->getSprite()->setColor(sf::Color(205, 82, 95, 255));
      }
      tookDamage = false;
    }
  }

  // Caso esteja indo para direita, coloca o sprite do jogador para a direita
  if (control.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (control.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }

  this->tryMove(movement, this);

  if (isSecondPlayer) {
    Jogador::playerTwoPosition = this->position;
  } else {
    Jogador::playerOnePosition = this->position;
  }
};

Jogador *Jogador::clone() {
  return new Jogador(this->position, this->isSecondPlayer);
}

void Jogador::receive(Entidade *entidade) {
  if (this->tookDamage == true)
    return;

  int beforeDamageHealth = this->health;
  entidade->deal(static_cast<Entidade *>(this));

  if (beforeDamageHealth != this->health) {
    this->tookDamage = true;

    if (this->health <= 0) {
      Jogador::dead = true;
    }

    this->invulnerableDeltaTime.restart();
  }
}

void Jogador::deal(Entidade *entidade) {
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

void Jogador::draw() {
  if (this->tookDamage) {
    // Efeito de piscadas
    int tick = invulnerableDeltaTime.getElapsedTime().asMilliseconds() % 5;
    // Seta transparencia
    if (tick == 0) {
      if (this->isSecondPlayer) {
        this->getSprite()->setColor(sf::Color(55, 171, 151, 150));
      } else {
        this->getSprite()->setColor(sf::Color(205, 82, 95, 150));
      }
    } else if (tick == 3) {
      if (this->isSecondPlayer) {
        this->getSprite()->setColor(sf::Color(55, 171, 151, 255));
      } else {
        this->getSprite()->setColor(sf::Color(205, 82, 95, 255));
      }
    }
  }

  this->graphicManager->draw(this->sprite);
}
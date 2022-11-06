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

  if (isSecondPlayer) {
    this->getSprite()->setColor(sf::Color::Green);
  } else {
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

  sf::Vector2f movement = Math::v_multi(control, velocity);

  // Caso esteja indo para direita, coloca o sprite do jogador para a direita
  if (control.x > 0) {
    SpriteManager::flipByXSprite(false, this->sprite);
  } else if (control.x < 0) {
    SpriteManager::flipByXSprite(true, this->sprite);
  }

  Jogador::position = movement;
  this->move(movement);
};
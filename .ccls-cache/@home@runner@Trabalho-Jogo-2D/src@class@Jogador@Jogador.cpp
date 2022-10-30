#include "Jogador.hpp"
#include "../../manager/KeyboardManager.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace Gerenciadores;
using namespace Entidades::Personagens;

Jogador::Jogador(){};

Jogador::Jogador(sf::Vector2f position, bool isSecondPlayer) : Personagem() {
  this->keyboardManager = KeyboardManager::getInstance();
  this->spriteManager = SpriteManager::getInstance();

  this->sprite = spriteManager->getSprite("assets/personagens/Jogador.png");
  std::cout << this->sprite->getPosition().x << '\n';
  this->sprite->setPosition(position);
  this->isSecondPlayer = isSecondPlayer;

  this->velocity = sf::Vector2f(0.1f, 0.1f);
};

Jogador::~Jogador(){};

sf::Sprite *Jogador::getSprite() { return this->sprite; };

bool Jogador::getIsSecondPlayer() { return this->isSecondPlayer; };

void Jogador::executar() {
  sf::Vector2f control;
  if (isSecondPlayer == false) {
    control = this->keyboardManager->getJogadorUmControl();
  }

  sf::Vector2f moviment(control.x * velocity.x, control.y * velocity.y);

  this->sprite->move(moviment);
};
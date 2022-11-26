#include "Ceifador.hpp"
#include "../../utils/Math.hpp"
#include "../Inimigo/Inimigo.hpp"
#include "../Jogador/Jogador.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace Utils;
using namespace Entidades::Personagens;

Ceifador::Ceifador(sf::Vector2f position, int patrolTiming)
    : Inimigo(position, false, patrolTiming, 50.0f) {
  this->setSprite(
      this->spriteManager->getSprite("assets/personagens/Ceifador.png"));

    this->countDown = 500;
};
Ceifador::~Ceifador(){
};

void Ceifador::patrol() {
  if (this->clock.getElapsedTime().asSeconds() >
      this->patrolDirectionTimerInSeconds) {

    sf::Vector2f dir;
    int rngDirX = rand() % 2;

    switch (rngDirX) {
    case 0:
      dir.x = 1;
      break;
    case 1:
      dir.x = -1;
      break;
    }

    this->patrolDirection = dir;
    this->clock.restart();
  }
}

void Ceifador::move() {
  countDown--;
  if(countDown == 0){
    this->projetil->randDirection();
    this->projetil->setAtivo(true);
    countDown = 500;
  } 
  if(projetil->getAtivo() == false){
    this->projetil->getSprite()->setPosition(this->getPosition());
  }
  
  sf::Vector2f gravity(0, 0.5f);
  sf::Vector2f movement = Math::v_sum(
      Math::v_multi(this->patrolDirection, this->velocity), gravity);
  this->tryMove(movement, this);
  this->patrol();
}

void Ceifador::draw() { this->graphicManager->draw(this->sprite); }

void Ceifador::setProjetil(Projetil *projetil){
  if(projetil == NULL){
    std::cout << "projetil nulo em classe Ceifador" << std::endl;
  }
  this->projetil = projetil;
}

Projetil* Ceifador::getProjetil() const{
  return this->projetil;
}

void Ceifador::deal(Entidade *entidade){
  try{
    Personagem *personagem = (Personagem*)entidade;

    if(personagem == NULL){
      throw 0;
    }

    for(int i=0; i < 10; i++)
      personagem->operator--();
  } catch(int errID){
    std::cout << "casting failed" << std::endl;
  }
}
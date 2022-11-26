#include "Projetil.hpp"
#include "../../utils/Math.hpp"
#include "../Personagem/Personagem.hpp"
#include <SFML/Graphics.hpp>

using namespace Utils;
using namespace Entidades;
using namespace Entidades::Personagens;

Projetil::Projetil(sf::Vector2f pos, bool flutuante) : Entidade(pos, flutuante) {
  this->setSprite(
      this->spriteManager->getSprite("assets/projetil/Projetil.png"));

  this->direction = sf::Vector2f(0, 0);
  this->sprite->setScale(0.5, 0.5);
  this->sprite->setOrigin(4, 4);
  this->setAtivo(false);
}

Projetil::~Projetil() {}

void Projetil::randDirection(){
  int r = rand()%2;
  if(r == 0){
    this->direction.x = 1;
  }
  else{
    this->direction.x = -1;
  }
}

void Projetil::move(){

  this->velocity = sf::Vector2f(0.2, 0.2);
  sf::Vector2f movement = Math::v_multi(direction, this->velocity);

  moveTo(movement);
    
}

void Projetil::draw(){

  this->graphicManager->draw(this->sprite); 
}

void Projetil::deal(Entidade *entidade){
  try{
    Personagem *personagem = (Personagem*)entidade;

    if(personagem == NULL){
      throw 0;
    }

    for(int i=0; i < 20; i++)
      personagem->operator--();

    std::cout << "dano projetil" << std::endl;
  } catch(int errID){
    std::cout << "casting failed" << std::endl;
  }
}

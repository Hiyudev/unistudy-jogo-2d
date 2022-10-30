#include "Personagem.hpp"
#include <iostream>
using namespace Entidades::Personagens;

Personagem::Personagem() : Entidade(){};

Personagem::~Personagem(){};

const int Personagem::getHealth() { return this->health; }

void Personagem::operator--() { this->health--; };

void Personagem::executar() {
  std::cout << "Movendo...";
}
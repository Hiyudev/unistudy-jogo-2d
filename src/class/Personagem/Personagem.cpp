#include "Personagem.hpp"

using namespace Entidades::Personagens;

Personagem::Personagem() : Entidade(){};

Personagem::~Personagem(){};

const int Personagem::getHealth() { return this->health; }

void Personagem::operator--() { this->health--; };
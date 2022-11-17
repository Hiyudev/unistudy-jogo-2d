#include "Fase.hpp"
#include "../../manager/CollisionManager.hpp"
#include "../Ente/Ente.hpp"
#include "../Jogador/Jogador.hpp"

using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Fases;

Fase::Fase() : Ente() {
  this->lista = new ListaEntidades();
  this->collisionManager = CollisionManager::getInstance();
}

Fase::~Fase() {
  int length = this->lista->getLength();
  for (int i = length - 1; i >= 0; i--) {
    Entidade *entidade = this->lista->getAt(i);
    delete entidade;
    this->lista->pop();
  }

  this->collisionManager->clear();

  delete this->lista;
};

void Fase::insertEntidade(Entidade *entidade) { this->lista->push(entidade); }
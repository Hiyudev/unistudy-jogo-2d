#include "Fase.hpp"
#include "../../manager/CollisionManager.hpp"
#include "../Ente/Ente.hpp"
#include "../Jogador/Jogador.hpp"

using namespace Gerenciadores;
using namespace Entidades::Personagens;
using namespace Fases;

Fase::Fase() : Ente(), lista() {
  this->collisionManager = CollisionManager::getInstance();
}

Fase::~Fase() {
  if (this->collisionManager != NULL) {
    delete this->collisionManager;
  }
};

void Fase::insertEntidade(Entidade *entidade) {
  this->lista.push(entidade);
}
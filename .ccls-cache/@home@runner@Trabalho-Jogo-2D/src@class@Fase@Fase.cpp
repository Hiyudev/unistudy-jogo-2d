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

Fase::~Fase(){};

void Fase::insertPlayer(Jogador *jogador) {
  this->lista.push(static_cast<Entidade *>(jogador));
}
#include "Ente.hpp"
#include "../../manager/SpriteManager.hpp"

using namespace Gerenciadores;
Ente::Ente() { this->spriteManager = SpriteManager::getInstance(); };

Ente::~Ente() { delete this->spriteManager; };

void Ente::executar(){};

void Ente::imprimirse(){};
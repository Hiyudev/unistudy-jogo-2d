#include "Ente.hpp"
#include "../../manager/GraphicManager.hpp"

using namespace Gerenciadores;

Ente::Ente() { this->graphicManager = GraphicManager::getInstance(); };
Ente::~Ente(){};
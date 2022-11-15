#include "ListaEntidades.hpp"
#include "../../manager/GraphicManager.hpp"
#include "../Entidade/Entidade.hpp"

using namespace Entidades;
using namespace Listas;

ListaEntidades::ListaEntidades() { gManager = GraphicManager::getInstance(); }

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::push(Entidade *entidade) { list += entidade; }

void ListaEntidades::executar() {
  for (int i = 0; i < list.getLength(); i++) {
    list[i]->executar();
  }
}

void ListaEntidades::draw() {
  for (int i = 0; i < list.getLength(); i++) {
    sf::Sprite *sprite = list[i]->getSprite();

    gManager->draw(sprite);
  }
}
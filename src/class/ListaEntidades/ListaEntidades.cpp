#include "ListaEntidades.hpp"
#include "../../manager/GraphicManager.hpp"
#include "../Entidade/Entidade.hpp"

using namespace Entidades;
using namespace Listas;

ListaEntidades::ListaEntidades() {
  this->graphicManager = GraphicManager::getInstance();
}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::push(Entidade *entidade) { list += entidade; }

void ListaEntidades::executar() {
  for (int i = 0; i < list.getLength(); i++) {

    if (i == 0) {
      std::cout << "Before" << '\n';
      std::cout << "x: " << list[i]->getSprite()->getPosition().x << '\n';
      std::cout << "y: " << list[i]->getSprite()->getPosition().y << '\n';
    }

    list[i]->executar();

    if (i == 0) {
      std::cout << "After" << '\n';
      std::cout << "x: " << list[i]->getSprite()->getPosition().x << '\n';
      std::cout << "y: " << list[i]->getSprite()->getPosition().y << '\n';
    }
  }
}
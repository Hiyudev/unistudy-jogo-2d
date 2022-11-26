#include "ListaEntidades.hpp"
#include "../../manager/GraphicManager.hpp"
#include "../Entidade/Entidade.hpp"

using namespace Entidades;
using namespace Listas;

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() { list.clear(); }

void ListaEntidades::push(Entidade *entidade) { list += entidade; }

void ListaEntidades::pop() { list.pop(); }

int ListaEntidades::getLength() { return this->list.getLength(); }

Entidade *ListaEntidades::getAt(int index) { return this->list.getAt(index); }

void ListaEntidades::executar() {
  for (int i = 0; i < list.getLength(); i++) {
    list[i]->executar();
  }
}

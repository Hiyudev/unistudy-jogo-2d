#include "ListaEntidades.hpp"
#include "../Entidade/Entidade.hpp"

using namespace Entidades;
using namespace Listas;

ListaEntidades::ListaEntidades() {}

ListaEntidades::~ListaEntidades() {}

void ListaEntidades::push(Entidade *entidade) { list.push(entidade); }

void ListaEntidades::executar() {
  for (int i = 0; i < list.getLength(); i++) {
    list[i]->executar();
  }
}
#pragma once

#include "../Lista/Lista.hpp"
#include "../Entidade/Entidade.hpp"
#include "../../manager/GraphicManager.hpp"

using namespace Listas;
using namespace Entidades;

namespace Listas {
	class ListaEntidades
	{
		private:
			Lista<Entidade*> list;
	
		public:
			ListaEntidades();
			~ListaEntidades();

			void push(Entidade* entidade);
			void pop();
			void executar();
			int getLength();
			Entidade* getAt(int index);
	};
}
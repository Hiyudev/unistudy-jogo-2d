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
			GraphicManager* graphicManager;
	
		public:
			ListaEntidades();
			~ListaEntidades();

			void push(Entidade* entidade);
			void executar();
	};
}
#include "../Lista/Lista.hpp"
#include "../Entidade/Entidade.hpp"

using namespace Listas;
using namespace Entidades;

namespace Listas {
	class ListaEntidades
	{
		private:
			Lista<Entidade> list;
	
		public:
			ListaEntidades();
			~ListaEntidades();

			void push(Entidade* entidade);
			void executar();
	};
}
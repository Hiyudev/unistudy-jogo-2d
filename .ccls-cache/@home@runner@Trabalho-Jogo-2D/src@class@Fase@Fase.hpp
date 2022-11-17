#pragma once

#include "../Ente/Ente.hpp"
#include "../Jogador/Jogador.hpp"
#include "../ListaEntidades/ListaEntidades.hpp"
#include "../../manager/CollisionManager.hpp"

using namespace Entidades::Personagens;
using namespace Gerenciadores;
using namespace Listas;

namespace Fases
{
	class Fase : public Ente {
		protected:
			CollisionManager* collisionManager;
			ListaEntidades* lista;

	  public:
	    Fase();
	    virtual ~Fase();

			void insertEntidade(Entidade* entidade);

	    virtual void executar() = 0;
			virtual void generate() = 0;
	};
}
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
      std::multimap<int, sf::Vector2f> map;

	  public:
	    Fase();
	    virtual ~Fase();

			void insertEntidade(Entidade* entidade);


      void createPlataforma(int posX, int posY);
      void createEspinho(int posX, int posY);
      void createGhoul(int posX, int posY);
      void createMorcego(int posX, int posY);
			void createCeifador(int posX, int posY);

      void createBorda(int mapKey);
      void pushEntidades();

      virtual void createMap() = 0;
	    virtual void executar() = 0;
			virtual void generate() = 0;
	};
}
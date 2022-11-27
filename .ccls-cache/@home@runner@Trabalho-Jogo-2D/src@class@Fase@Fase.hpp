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

			void insertPlayer(Entidade* player);
      int getCont() { return this->cont_inimigos; }

      void insertPlataforma(int posX, int posY);
      void insertEspinho(int posX, int posY);
      void insertGhoul(int posX, int posY);
      void insertMorcego(int posX, int posY);
      void insertCeifador(int posX, int posY);
      
      void insertBorda(int mapKey);
      void createEntidades();
      void checkInimigosVivos();

      virtual void createMap() = 0;
	    virtual void executar() = 0;
			virtual void generate() = 0;
	};
}
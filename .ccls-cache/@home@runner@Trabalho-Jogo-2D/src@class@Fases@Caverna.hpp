#pragma once

#include "../Fase/Fase.hpp"
#include <SFML/Graphics.hpp>
#include <map>

namespace Fases
{
	class Caverna : public Fase
	{
		private:
			int id;

		public:
			Caverna();
			virtual ~Caverna();

      void createMap();
			void executar();
			void generate();
	};
}
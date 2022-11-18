#pragma once

#include "../Fase/Fase.hpp"
#include <SFML/Graphics.hpp>
#include <map>

namespace Fases
{
	class Caverna : public Fase
	{
		private:
			//std::multimap<int, sf::Vector2f> map;

		public:
			Caverna();
			~Caverna();

      void createMap();
			void executar();
			void generate();
	};
}
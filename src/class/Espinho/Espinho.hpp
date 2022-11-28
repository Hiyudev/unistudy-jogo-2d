#pragma once
#include <SFML/Graphics.hpp>
#include "../Obstaculo/Obstaculo.hpp"

namespace Entidades
{
	namespace Obstaculos
	{
		class Espinho : public Obstaculo
		{  
      private: 
        float height;
			public:
				Espinho(sf::Vector2f position);
        Espinho(sf::Vector2f position, float height);
				~Espinho();

				void deal(Entidade* entidade);
        void randomHeight();
		};
	}
}
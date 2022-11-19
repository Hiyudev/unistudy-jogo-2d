#include <SFML/Graphics.hpp>
#include "../Obstaculo/Obstaculo.hpp"

namespace Entidades
{
	namespace Obstaculos
	{
		class Plataforma : public Obstaculo
		{  
      private: 
        float width;
			public:
				Plataforma(sf::Vector2f position);
        Plataforma(sf::Vector2f position, float width);
				~Plataforma();

        void randomWidth();
		};
	}
}
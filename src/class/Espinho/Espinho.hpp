#include <SFML/Graphics.hpp>
#include "../Obstaculo/Obstaculo.hpp"

namespace Entidades
{
	namespace Obstaculos
	{
		class Espinho : public Obstaculo
		{
			public:
				Espinho(sf::Vector2f position);
				~Espinho();
		};
	}
}
#include <SFML/Graphics.hpp>
#include "../Obstaculo/Obstaculo.hpp"

namespace Entidades
{
	namespace Obstaculos
	{
		class Bloco : public Obstaculo
		{
			public:
				Bloco(sf::Vector2f position);
				virtual ~Bloco();
		};
	}
}
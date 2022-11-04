#include <SFML/Graphics.hpp>
#include "../Obstaculo/Obstaculo.hpp"

namespace Entidades
{
	namespace Obstaculos
	{
		class Caixa : public Obstaculo
		{
			public:
				Caixa(sf::Vector2f position);
				~Caixa();

				void executar();
		};
	}
}
#include <SFML/Graphics.hpp>
#include "../Obstaculo/Obstaculo.hpp"

namespace Entidades
{
	namespace Obstaculos
	{
		class Caixa : public Obstaculo
		{  
      private: 
        float width;
			public:
				Caixa(sf::Vector2f position);
        Caixa(sf::Vector2f position, float width);
				~Caixa();

        void randomWidth();
		};
	}
}
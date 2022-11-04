#include <SFML/Graphics.hpp>
#include "../Inimigo/Inimigo.hpp"

using namespace Entidades::Personagens;

namespace Entidades {
	namespace Personagens {
		class Morcego : public Inimigo {
			public:
				Morcego(sf::Vector2f position);
				~Morcego();

				void patrol();
				void executar();
		};
	}
}
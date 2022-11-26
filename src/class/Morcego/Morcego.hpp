#include <SFML/Graphics.hpp>
#include "../Inimigo/Inimigo.hpp"

using namespace Entidades::Personagens;

namespace Entidades {
	namespace Personagens {
		class Morcego : public Inimigo {
			private:
				bool isVampiro;

			public:
				Morcego(sf::Vector2f position, int patrolTiming);
				virtual ~Morcego();

				void patrol();
				void move();
        void deal(Entidade* entidade);
		};
	}
}
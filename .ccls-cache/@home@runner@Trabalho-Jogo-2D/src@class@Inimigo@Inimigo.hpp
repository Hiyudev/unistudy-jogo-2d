#pragma once

#include <SFML/Graphics.hpp>
#include "../Personagem/Personagem.hpp"

using namespace Entidades::Personagens;

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
			protected:
				sf::Vector2f patrolDirection;
				sf::Clock clock;

				int patrolDirectionTimerInSeconds;
				float playerDetectionRadius;

			public:
				Inimigo(sf::Vector2f position, bool flutuante, int patrolDirectionTimerInSeconds, float playerDetectionRadius);
				~Inimigo();

				bool isPlayerNearby();

				virtual void patrol() = 0;
		};
	}
}
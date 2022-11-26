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
				virtual ~Inimigo();

				bool isPlayerNearby();

        sf::Vector2f getPatrolDirection();

				virtual void deal(Entidade* entidade);
				virtual void receive(Entidade* entidade);
				virtual void patrol() = 0;
		};
	}
}
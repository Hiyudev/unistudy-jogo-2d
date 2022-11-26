#pragma once
#include <SFML/Graphics.hpp>
#include "../Entidade/Entidade.hpp"

namespace Entidades {
  namespace Obstaculos {
    class Obstaculo : public Entidade {
			protected:
				bool dealsDamage;

      public:
        Obstaculo(sf::Vector2f position, bool dealsDamage);
        virtual ~Obstaculo();

				virtual void deal(Entidade* entidade);
				bool getDealsDamage();
    };
  }
}
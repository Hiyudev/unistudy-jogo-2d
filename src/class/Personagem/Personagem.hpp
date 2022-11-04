#pragma once
#include "../Entidade/Entidade.hpp"
#include <SFML/Graphics.hpp>

using namespace Gerenciadores;

namespace Entidades {
  namespace Personagens {
    class Personagem : public Entidade {
      protected:
        int health;
        sf::Vector2f velocity;

      public:
        Personagem(sf::Vector2f position = sf::Vector2f(0,0), int health = 3, sf::Vector2f vel = sf::Vector2f(0.1f, 0.1f));
        ~Personagem();

        const int getHealth();
        void setHealth(const int health);

        void operator --();

				virtual void move(sf::Vector2f direction);
        virtual void executar();
    };
  }
}
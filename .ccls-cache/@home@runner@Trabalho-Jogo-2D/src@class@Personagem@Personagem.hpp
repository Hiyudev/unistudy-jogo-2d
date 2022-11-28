#pragma once
#include "../../manager/CollisionManager.hpp"
#include "../Entidade/Entidade.hpp"
#include <SFML/Graphics.hpp>

using namespace Gerenciadores;

namespace Entidades {
  namespace Personagens {
    class Personagem : public Entidade {
      protected:
        int health;
				bool isJumping;
				bool isTouchingGround;
				sf::Vector2f velocity;

      public:
        Personagem(sf::Vector2f position = sf::Vector2f(0,0), bool flutuante = false,int health = 3, sf::Vector2f vel = sf::Vector2f(0.1f, 0.1f));
        virtual ~Personagem();

				// Getters
        const int getHealth() const;
				// Setters
				void setHealth(const int health);

				// Overloading operator
        void operator --();

				bool canMove(sf::Vector2f direction, Personagem* personagem = NULL);
				void tryMove(sf::Vector2f direction, Personagem* personagem = NULL);
    };
  }
}
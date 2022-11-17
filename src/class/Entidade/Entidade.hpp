#pragma once
#include <SFML/Graphics.hpp>
#include "../Ente/Ente.hpp"
#include "../../manager/SpriteManager.hpp"
#include "../../manager/CollisionManager.hpp"

namespace Gerenciadores {
	class CollisionManager;
}

using namespace Gerenciadores;

// Abstract class do padrão de projeto Template Method
// Código inspirado e retirado do website:
// https://refactoring.guru/pt-br/design-patterns/template-method/cpp/example
namespace Entidades {
  class Entidade : public Ente {
    protected:
			// Parte grafica
			SpriteManager* spriteManager;
			sf::Sprite* sprite;

			CollisionManager* collisionManager;

			// Parte de movimento
      sf::Vector2f position;

			// Atributos
			bool flutuante;

			// Base Operation
			void gravity();
			void voar();
			virtual void draw();
			virtual void move();

    public:
      Entidade(sf::Vector2f pos = sf::Vector2f(0, 0), bool flutuante = false);
      ~Entidade();

			// Getters
			sf::Sprite* getSprite();
			// Setters
			void setSprite(sf::Sprite* sprite);

			// Metodos
			void moveTo(sf::Vector2f direction);

			// Skeleton Operation
      void executar();

			// Clone prototype
			virtual Entidade* clone();
  };
}
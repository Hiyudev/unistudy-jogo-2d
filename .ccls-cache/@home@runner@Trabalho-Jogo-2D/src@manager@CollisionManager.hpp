#pragma once

#include "../class/Entidade/Entidade.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

#include <vector>
#include <list>
namespace Entidades {
	class Entidade;
}
using namespace Entidades;

namespace Gerenciadores
{
  class CollisionManager
  {
    private:
      inline static CollisionManager* _manager;
      inline static std::mutex _mutex;
      CollisionManager();

			std::vector<Entidade*> obstaculosList;
			std::list<Entidade*> inimigosList;

    public:
      ~CollisionManager();

      static CollisionManager *getInstance();

			void pushObstaculo(Entidade* obstaculo);
			void pushInimigo(Entidade* inimigo);

			bool canMoveTo(sf::Vector2f position, sf::Vector2f direction);
			bool canMoveTo(sf::Vector2f position, sf::Vector2f direction, bool* takeDamage);
      bool checkCollideInimigo(sf::FloatRect hitbox, sf::Vector2f direction);
      bool checkCollideInimigo(sf::FloatRect hitbox, sf::Vector2f direction, bool* takeDamage);
      bool checkCollideObstaculo(sf::FloatRect hitbox, sf::Vector2f direction);
      bool checkCollideObstaculo(sf::FloatRect hitbox, sf::Vector2f direction, bool* takeDamage);
  };
}
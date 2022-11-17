#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../Personagem/Personagem.hpp"
#include "../../manager/KeyboardManager.hpp"

using namespace Gerenciadores;

namespace Entidades
{
  namespace Personagens
  {
    class Jogador : public Personagem
    {
      private:
        bool isSecondPlayer;
				bool isJumping;
				bool tookDamage;
				sf::Clock jumpDeltaTime;
				sf::Clock invulnerableDeltaTime;

        KeyboardManager* keyboardManager;
      
      public:
        Jogador(sf::Vector2f position, bool isSecondPlayer);
        ~Jogador();

				static sf::Vector2f playerOnePosition;
				static sf::Vector2f playerTwoPosition;
				static bool hasSecondPlayer;
				
        bool getIsSecondPlayer();

				void move();
				Entidade* clone();
				void knockback(sf::Vector2f direction);
    };
  }
}
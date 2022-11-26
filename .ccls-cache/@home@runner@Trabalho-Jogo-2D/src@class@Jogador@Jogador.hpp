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
        virtual ~Jogador();

				static bool dead;
				static bool hasSecondPlayer;
				static sf::Vector2f playerOnePosition;
				static sf::Vector2f playerTwoPosition;
				
        bool getIsSecondPlayer();

				void receive(Entidade* entidade);
				void deal(Entidade* entidade);
				void move();
				void draw();
				Jogador* clone();
				void knockback(sf::Vector2f direction);
    };
  }
}
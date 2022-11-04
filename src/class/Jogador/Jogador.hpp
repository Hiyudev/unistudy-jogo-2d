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
        KeyboardManager* keyboardManager;
        bool isSecondPlayer;
      
      public:
        Jogador(sf::Vector2f position, bool isSecondPlayer);
        ~Jogador();

				static sf::Vector2f position;
				
        bool getIsSecondPlayer();

				void move(sf::Vector2f direction);
        void executar();
    };
  }
}
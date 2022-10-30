#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../Personagem/Personagem.hpp"
#include "../../manager/KeyboardManager.hpp"
#include "../../manager/SpriteManager.hpp"

using namespace Gerenciadores;

namespace Entidades
{
  namespace Personagens
  {
    class Jogador : public Personagem
    {
      private:
        KeyboardManager* keyboardManager;
				SpriteManager* spriteManager;

        sf::Sprite* sprite;
        sf::Vector2f velocity;

        bool isSecondPlayer;
      
      public:
        Jogador();
        Jogador(sf::Vector2f position, bool isSecondPlayer);
        ~Jogador();

        sf::Sprite* getSprite();

        bool getIsSecondPlayer();

        void executar();
    };
  }
}
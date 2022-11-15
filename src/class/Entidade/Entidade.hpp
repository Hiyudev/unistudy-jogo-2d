#pragma once
#include <SFML/Graphics.hpp>
#include "../Ente/Ente.hpp"
#include "../../manager/SpriteManager.hpp"

using namespace Gerenciadores;

namespace Entidades {
  class Entidade : public Ente {
    protected:
			SpriteManager* spriteManager;
      sf::Vector2f pos;
			sf::Sprite* sprite;
  
    public:
      Entidade(sf::Vector2f pos);
      ~Entidade();

			sf::Sprite* getSprite();
			void setSprite(sf::Sprite* sprite);

      virtual void executar() = 0;
  };
}
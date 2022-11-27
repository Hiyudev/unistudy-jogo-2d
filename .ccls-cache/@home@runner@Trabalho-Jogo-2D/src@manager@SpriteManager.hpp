#pragma once

#include <iostream>
#include <string>
#include <mutex>
#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
  class SpriteManager
  {
    private:
      inline static SpriteManager* _manager;
      inline static std::mutex _mutex;
      SpriteManager();

    public:
      ~SpriteManager();

      static SpriteManager *getInstance();

			sf::Sprite* getSprite(std::string filePath);
			static void flipByXSprite(bool value, sf::Sprite *sprite);
  };
}
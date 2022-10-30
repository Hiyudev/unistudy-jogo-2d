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
      ~SpriteManager();

    public:
      static SpriteManager *getInstance();

			sf::Sprite* getSprite(std::string filePath);
  };
}
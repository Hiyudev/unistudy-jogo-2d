#pragma once

#include <iostream>
#include <mutex>
#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
  class GraphicManager
  {
    private:
      sf::RenderWindow* window;
      inline static GraphicManager* _manager;
      inline static std::mutex _mutex;

    public:
      GraphicManager();
      ~GraphicManager();

      static GraphicManager *getInstance();

      sf::RenderWindow* getWindow();
  };
}
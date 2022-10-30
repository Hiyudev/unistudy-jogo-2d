#pragma once

#include <iostream>
#include <mutex>
#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
  class EventManager
  {
    private:
      inline static EventManager* _manager;
      inline static std::mutex _mutex;
      EventManager();
      ~EventManager();

    public:
      static EventManager *getInstance();

      sf::Vector2f getJogadorUmControl();
  };
}
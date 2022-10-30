#pragma once

#include <iostream>
#include <mutex>
#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
  class KeyboardManager
  {
    private:
      inline static KeyboardManager* _manager;
      inline static std::mutex _mutex;
      KeyboardManager();
      ~KeyboardManager();

    public:
      static KeyboardManager *getInstance();

      sf::Vector2f getJogadorUmControl();
  };
}
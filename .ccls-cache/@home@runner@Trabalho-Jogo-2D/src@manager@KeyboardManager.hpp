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

    public:
      ~KeyboardManager();

      static KeyboardManager *getInstance();

      sf::Vector2f getJogadorUmControl();
      sf::Vector2f getJogadorDoisControl();
  };
}
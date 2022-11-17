#pragma once

#include "../Fase/Fase.hpp"
#include <SFML/Graphics.hpp>
#include <map>

namespace Fases{
  class Ruinas : public Fase
  {
  private:
    std::multimap<int, sf::Vector2f> map;
  
  public:
    Ruinas();
    ~Ruinas();
  
    void generate();
    void executar();
  };
}
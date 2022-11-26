#pragma once

#include "../Fase/Fase.hpp"
#include <SFML/Graphics.hpp>
#include <map>

namespace Fases{
  class Ruina : public Fase
  {
  private:
    int id;
  
  public:
    Ruina();
    virtual ~Ruina();

    void createMap();
    void generate();
    void executar();
  };
}
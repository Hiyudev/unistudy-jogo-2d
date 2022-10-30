#pragma once
#include "../Ente/Ente.hpp"

namespace Entidades {
  class Entidade : public Ente {
    protected:
      int x;
      int y;
  
    public:
      Entidade();
      ~Entidade();
      virtual void executar() = 0;
  };
}
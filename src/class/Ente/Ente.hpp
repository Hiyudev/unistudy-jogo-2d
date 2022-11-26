#pragma once
#include "../../manager/GraphicManager.hpp"

using namespace Gerenciadores;

class Ente {
  protected:
		GraphicManager* graphicManager;

  public:
    Ente();
    virtual ~Ente();

    virtual void executar() = 0;
};
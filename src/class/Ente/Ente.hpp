#pragma once
#include "../../manager/GraphicManager.hpp"

using namespace Gerenciadores;

class Ente {
  protected:
    int id;
		GraphicManager* graphicManager;

  public:
    Ente();
    ~Ente();
    virtual void executar() = 0;
    void imprimirse();
};
#pragma once
#include "../../manager/SpriteManager.hpp"

using namespace Gerenciadores;

class Ente {
  protected:
    int id;
		SpriteManager* spriteManager;

  public:
    Ente();
    ~Ente();
    virtual void executar() = 0;
    void imprimirse();
};
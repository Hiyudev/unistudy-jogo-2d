#include "../Ente/Ente.hpp"

class Fase : public Ente {
  public:
    Fase();
    ~Fase();
    virtual void executar() = 0;
    void gerenciar_colisoes();
};
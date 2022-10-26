#include <SFML/Graphics.hpp>
#include "class/Jogador/Jogador.hpp"
#include "manager/GraphicManager.hpp"

using namespace Gerenciadores;

class Jogo {
  private:
    Jogador JogadorUm;
    GraphicManager graphicManager;

  public:
    Jogo();
    ~Jogo();
    void executar();
};

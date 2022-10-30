#include <SFML/Graphics.hpp>
#include "class/Jogador/Jogador.hpp"
#include "manager/GraphicManager.hpp"
#include <iostream>
using namespace std;
using namespace Gerenciadores;
using namespace Entidades::Personagens;

class Jogo {
  private:
    const static string nome;

    Jogador JogadorUm;
    GraphicManager* graphicManager;

  public:
    Jogo();
    ~Jogo();
    void executar();

    const static string getNome();
};

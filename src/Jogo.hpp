#include <SFML/Graphics.hpp>
#include "class/Fases/FaseUm.hpp"
#include "class/Jogador/Jogador.hpp"
#include "class/ListaEntidades/ListaEntidades.hpp"
#include "manager/GraphicManager.hpp"
#include <iostream>
#include <string>

using namespace Fases;
using namespace Gerenciadores;
using namespace Entidades::Personagens;

class Jogo {
  private:
    const static std::string nome;

		Jogador JogadorUm;
		Jogador JogadorDois;

		FaseUm faseUm;

		GraphicManager* graphicManager;

  public:
    Jogo();
    ~Jogo();
    void executar();

    const static std::string getNome();
};

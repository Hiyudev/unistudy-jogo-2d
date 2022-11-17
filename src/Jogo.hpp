#include <SFML/Graphics.hpp>
#include "class/Fase/Fase.hpp"
#include "class/Fases/Caverna.hpp"
#include "class/Fases/Ruinas.hpp"
#include "class/Jogador/Jogador.hpp"
#include "class/Menu/Menu.hpp"
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
		static bool hasJogadorDois;

		Jogador JogadorUm;
		Jogador JogadorDois;

    Menu menu;

		Fase* fase;

		GraphicManager* graphicManager;

  public:
    Jogo();
    ~Jogo();

    void executar();
    const static std::string getNome();
};

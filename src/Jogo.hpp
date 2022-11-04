#include <SFML/Graphics.hpp>
#include "class/Caixa/Caixa.hpp"
#include "class/Bloco/Bloco.hpp"
#include "class/Jogador/Jogador.hpp"
#include "class/Morcego/Morcego.hpp"
#include "class/ListaEntidades/ListaEntidades.hpp"
#include "manager/GraphicManager.hpp"
#include <iostream>
#include <string>

using namespace Gerenciadores;
using namespace Entidades::Obstaculos;
using namespace Entidades::Personagens;

class Jogo {
  private:
    const static std::string nome;

		ListaEntidades entidades;

    Jogador JogadorUm;
		Morcego morcego;
		Bloco blocoUm;
		Bloco blocoDois;
		Caixa caixaUm;
		
    GraphicManager* graphicManager;

  public:
    Jogo();
    ~Jogo();
    void executar();

    const static std::string getNome();
};

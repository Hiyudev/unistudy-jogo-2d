#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class Constants {
  public:
    const static string name;

    const static sf::Keyboard::Key jogadorUmEsquerda;
    const static sf::Keyboard::Key jogadorUmDireita;
    const static sf::Keyboard::Key jogadorUmCima;
    const static sf::Keyboard::Key jogadorUmBaixo;

    const static sf::Keyboard::Key jogadorDoisEsquerda;
    const static sf::Keyboard::Key jogadorDoisDireita;
    const static sf::Keyboard::Key jogadorDoisCima;
    const static sf::Keyboard::Key jogadorDoisBaixo;
};

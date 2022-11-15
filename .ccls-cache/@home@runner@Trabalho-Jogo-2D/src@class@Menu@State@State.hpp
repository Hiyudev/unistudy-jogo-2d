#pragma once

#include "../Menu.hpp"
class Menu;

/**
* Código retirado no website https://refactoring.guru/design-patterns/state/cpp/example
* para meios didáticos, afim de compreender o padrão de projeto State usando exemplos
* de código.
*/
class State {
 	protected:
  	Menu *menu;

 public:
  virtual ~State() {
  }

  void setMenu(Menu *menu) {
    this->menu = menu;
  }

  virtual void executar() = 0;
};

#pragma once

#include "../Menu.hpp"
class Menu;

/**
* Código retirado no website https://refactoring.guru/design-patterns/state/cpp/example
* para meios didáticos, afim de compreender o padrão de projeto State usando exemplos
* de código.
*/
class StateMenu {
 	protected:
  	Menu *menu;

 	public:
		StateMenu();
  	virtual ~StateMenu();
	
	  void setMenu(Menu *menu);
		virtual void generate() = 0;
	  virtual void executar() = 0;
};

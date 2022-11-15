#pragma once
#include "StateMenu/StateMenu.hpp"
#include "../Lista/Lista.hpp"
#include "../Ente/Ente.hpp"
#include "../Fases/Caverna.hpp"
#include <SFML/Graphics.hpp>

using namespace Listas;
using namespace Fases;
class StateMenu;

// Menu é o "context"
class Menu : public Ente {
  private:
		StateMenu* state;

    sf::RenderWindow *window;
    Caverna *pCaverna;

    int selectedItem;

    sf::Font font;
		Lista<sf::Text*>* textList;

  public:
    Menu(StateMenu* state);
    ~Menu();

		void transitionTo(StateMenu* state);

    void selectUp();
    void selectDown();
    void manageEvents();

		const sf::Font getFont() const;
    const int getSelectedItem() const;
	 	Lista<sf::Text*>* getTextList();

    void executar();
    void draw();
};
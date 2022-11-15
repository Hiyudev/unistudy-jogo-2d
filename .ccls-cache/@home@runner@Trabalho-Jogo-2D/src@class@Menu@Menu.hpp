#pragma once
#include <iostream>
#include <vector>
#include "../Ente/Ente.hpp"
#include "../Fases/Caverna.hpp"

using namespace Fases;

class Menu : public Ente {
  private:
    sf::RenderWindow *window;
    std::vector<sf::Text*> textList;
    sf::Font font;

		int playersCount;
		int worldID;
    int selectedItem;

		bool started;

  public:
    Menu();
    ~Menu();

    void selectUp();
    void selectDown();
    void manageEvents();
    void executar();
    void draw();

		const bool getStarted() const;

    const int getSelectedItem() const;
		const int getWorldID() const;
		const int getPlayersCount() const;
};
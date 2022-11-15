#pragma once
#include "../Ente/Ente.hpp"
#include "../Fases/Caverna.hpp"
#define MAX_ITENS 4

using namespace Fases;

class Menu : public Ente {
  private:
    sf::RenderWindow *window;

    int selectedItem;

    sf::Font font;
    sf::Text menu[4];

  public:
    Menu();
    ~Menu();

    void selectUp();
    void selectDown();
    void manageEvents();
    const int getSelectedItem() const;
    void executar();
    void draw();
};
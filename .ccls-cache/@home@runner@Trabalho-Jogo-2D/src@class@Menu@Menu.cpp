#include "Menu.hpp"
#include "../Fases/Caverna.hpp"
#include <iostream>

using namespace Fases;

Menu::Menu() {
  this->window = this->graphicManager->getWindow();
  float width = window->getSize().x;
  float height = window->getSize().y;

  selectedItem = 0;

  if (!font.loadFromFile("assets/fontes/monogram.ttf")) {
    std::cout << "Erro ao tentar carregar fonte arial" << '\n';
  }

  menu[0].setFont(font);
  menu[0].setFillColor(sf::Color::Red);
  menu[0].setString("Start");
  menu[0].setPosition(sf::Vector2f(width / 4, height / (MAX_ITENS + 1) * 1));

  menu[1].setFont(font);
  menu[1].setFillColor(sf::Color::White);
  menu[1].setString("Fase: Caverna");
  menu[1].setPosition(sf::Vector2f(width / 4, height / (MAX_ITENS + 1) * 2));

  menu[2].setFont(font);
  menu[2].setFillColor(sf::Color::White);
  menu[2].setString("Jogadores");
  menu[2].setPosition(sf::Vector2f(width / 4, height / (MAX_ITENS + 1) * 3));

  menu[3].setFont(font);
  menu[3].setFillColor(sf::Color::White);
  menu[3].setString("Quit");
  menu[3].setPosition(sf::Vector2f(width / 4, height / (MAX_ITENS + 1) * 4));
};

Menu::~Menu(){};

const int Menu::getSelectedItem() const { return this->selectedItem; }

void Menu::executar() {
  manageEvents();
  draw();
}

void Menu::draw() {
  for (int i = 0; i < MAX_ITENS; i++) {
    window->draw(menu[i]);
  }
}

void Menu::selectUp() {
  if (selectedItem - 1 >= 0) {
    menu[selectedItem].setFillColor(sf::Color::White);
    selectedItem--;
    menu[selectedItem].setFillColor(sf::Color::Red);
  }
}

void Menu::selectDown() {
  if (selectedItem + 1 < MAX_ITENS) {
    menu[selectedItem].setFillColor(sf::Color::White);
    selectedItem++;
    menu[selectedItem].setFillColor(sf::Color::Red);
  }
}

void Menu::manageEvents() {
  sf::Event event;
  while (window->pollEvent(event)) {

    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Up)
        this->selectUp();
      if (event.key.code == sf::Keyboard::Down)
        this->selectDown();
      if (event.key.code == sf::Keyboard::Return) {
        if (this->getSelectedItem() == 0) {
          // Start
        }
        if (this->getSelectedItem() == 1) {
          std::cout << "..." << std::endl;
        }
        if (this->getSelectedItem() == 2) {
          // Jogadores
        }
        if (this->getSelectedItem() == 3) {
          window->close();
        }
      }
      if (event.key.code == sf::Keyboard::Escape) {
        window->close();
      }
    }

    if (event.type == sf::Event::Closed) {
      window->close();
    }
  }
}
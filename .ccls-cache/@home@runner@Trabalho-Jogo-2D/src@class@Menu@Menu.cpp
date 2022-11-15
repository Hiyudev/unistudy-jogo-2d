
#include "Menu.hpp"
#include "../Fases/Caverna.hpp"
#include "StateMenu/StateMenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

using namespace Fases;

Menu::Menu(StateMenu *state) {
  this->state = NULL;
  this->textList = new Lista<sf::Text*>();
  this->window = this->graphicManager->getWindow();
  float width = window->getSize().x;
  float height = window->getSize().y;

  selectedItem = 0;

  if (!font.loadFromFile("assets/fontes/monogram.ttf")) {
    std::cout << "Erro ao tentar carregar fonte arial" << '\n';
  }

  std::cout << "Menu constructor - before transitionTo" << '\n';

  this->transitionTo(state);

  std::cout << "Menu constructor - after transitionTo" << '\n';
};

Menu::~Menu() {
  if (this->state != NULL) {
    delete this->state;
  }
};

void Menu::transitionTo(StateMenu *state) {
  std::cout << "Is state null? " << (state == NULL) << '\n';

  if (this->state != NULL) {
    std::cout << "What" << '\n';
    delete this->state;
  }

  std::cout << "Menu transitionTo - set menu" << '\n';
  state->setMenu(this);
  std::cout << "Menu transitionTo - before generate" << '\n';
  state->generate();
  std::cout << "Menu transitionTo - after generate" << '\n';
  this->state = state;
}

const int Menu::getSelectedItem() const { return this->selectedItem; }
const sf::Font Menu::getFont() const { return this->font; }
Lista<sf::Text*> *Menu::getTextList() { return this->textList; }

void Menu::executar() {
  std::cout << "Menu executar - executar" << '\n';
  std::cout << "Menu executar - draw" << '\n';
  draw();
  std::cout << "Menu executar - manageEvents" << '\n';
  manageEvents();
}

void Menu::draw() {
  std::cout << "Menu draw" << '\n';
  std::cout << "length " << textList->getLength() << '\n';
  for (int i = 0; i < textList->getLength(); i++) {
    sf::Text *text = textList->getAt(i);
    std::string w = text->getString();
    std::cout << "text: " << w << '\n';
    std::cout << "window exists? " << (window != NULL) << '\n';
    this->window->draw(*text);
  }
}

void Menu::selectUp() {
  if (selectedItem - 1 >= 0) {
    (*textList)[selectedItem]->setFillColor(sf::Color::White);
    selectedItem--;
    (*textList)[selectedItem]->setFillColor(sf::Color::Red);
  }
}

void Menu::selectDown() {
  if (selectedItem + 1 < textList->getLength()) {
    (*textList)[selectedItem]->setFillColor(sf::Color::White);
    selectedItem++;
    (*textList)[selectedItem]->setFillColor(sf::Color::Red);
  }
}

void Menu::manageEvents() {
  std::cout << "Menu manage events" << '\n';
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
          pCaverna->executar();
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
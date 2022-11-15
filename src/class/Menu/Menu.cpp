#include <iostream>
#include <vector>
#include "Menu.hpp"
#include "../Fases/Caverna.hpp"
#include <iostream>

using namespace Fases;

Menu::Menu() {
  this->window = this->graphicManager->getWindow();
  this->playersCount = 1;
  this->worldID = 1;
  this->selectedItem = 0;
	this->started = false;

  if (!font.loadFromFile("assets/fontes/monogram.ttf")) {
    std::cout << "Erro ao tentar carregar fonte arial" << '\n';
  }

  sf::Text *startTextOption = new sf::Text();
  startTextOption->setFont(font);
  startTextOption->setFillColor(sf::Color::Red);
  startTextOption->setString("Start");
  textList.push_back(startTextOption);

  sf::Text *faseTextOption = new sf::Text();
  faseTextOption->setFont(font);
  faseTextOption->setFillColor(sf::Color::White);
  faseTextOption->setString("Fase: Caverna");
  textList.push_back(faseTextOption);

  sf::Text *jogadorTextOption = new sf::Text();
  jogadorTextOption->setFont(font);
  jogadorTextOption->setFillColor(sf::Color::White);
  jogadorTextOption->setString("Jogadores: 1");
  textList.push_back(jogadorTextOption);

  sf::Text *quitTextOption = new sf::Text();
  quitTextOption->setFont(font);
  quitTextOption->setFillColor(sf::Color::White);
  quitTextOption->setString("Quit");
  textList.push_back(quitTextOption);
};

Menu::~Menu(){};

const int Menu::getSelectedItem() const { return this->selectedItem; }

const bool Menu::getStarted() const { return this->started;}
const int Menu::getWorldID() const { return this->worldID;}
const int Menu::getPlayersCount() const { return this->playersCount;}
void Menu::executar() {
  manageEvents();
  draw();
}

void Menu::draw() {
	std::vector<sf::Text*>::iterator it;
	int i = 1;
	
	for(it = textList.begin(); it != textList.end(); it++) {
		sf::Text* text = *it;
  float width = window->getSize().x;
  float height = window->getSize().y;
		
		text->setPosition(sf::Vector2f(width / 4, height / (textList.size() + 1) * i));
    window->draw(*text);
		i++;
	}
}

void Menu::selectUp() {
  if (selectedItem - 1 >= 0) {
    textList[selectedItem]->setFillColor(sf::Color::White);
    selectedItem--;
    textList[selectedItem]->setFillColor(sf::Color::Red);
  }
}

void Menu::selectDown() {
  if (selectedItem + 1 < this->textList.size()) {
    textList[selectedItem]->setFillColor(sf::Color::White);
    selectedItem++;
    textList[selectedItem]->setFillColor(sf::Color::Red);
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
      if (event.key.code == sf::Keyboard::Enter) {
        if (this->getSelectedItem() == 0) {
          this->started = true;
        }
        if (this->getSelectedItem() == 1) {
          if (worldID == 1) {
            worldID = 2;
          } else {
            worldID = 1;
          }

          sf::Text* text = textList[1];
          switch (this->worldID) {
          case 1:
            text->setString("Fase: Caverna");
            break;
          case 2:
            text->setString("Fase: Ruinas");
            break;
          }
        }
        if (this->getSelectedItem() == 2) {
          if (playersCount == 1) {
            playersCount = 2;
          } else {
            playersCount = 1;
          }

          sf::Text* text = textList[2];
          switch (this->playersCount) {
          case 1:
            text->setString("Jogadores: 1");
            break;
          case 2:
            text->setString("Jogadores: 2");
            break;
          }
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
#include "StartMenu.hpp"
#include "../../Lista/Lista.hpp"
#include <iostream>

StartMenu::StartMenu() : StateMenu(){};
StartMenu::~StartMenu() {
  Lista<sf::Text*> *list = this->menu->getTextList();
  for (int i = 0; i < list->getLength(); i++) {
    list->pop();
  }
};

void StartMenu::generate() {
  std::cout << "Start menu generate method..." << '\n';
  if (this->menu != NULL) {
    Lista<sf::Text*> *list = this->menu->getTextList();
    sf::Font font = this->menu->getFont();

    sf::Text *text1 = new sf::Text();
    text1->setFont(font);
    text1->setFillColor(sf::Color::Red);
    text1->setString("Start");

    list->push(text1);

    sf::Text *text2 = new sf::Text();
    text2->setFont(font);
    text2->setFillColor(sf::Color::White);
    text2->setString("Quit");

    list->push(text2);
  } else {
    std::cout << "Erro ao tentar acessar o objeto Menu" << '\n';
  }
  std::cout << "Finish menu generate method..." << '\n';
}
void StartMenu::executar() { std::cout << "StartMenu executar..." << '\n'; };
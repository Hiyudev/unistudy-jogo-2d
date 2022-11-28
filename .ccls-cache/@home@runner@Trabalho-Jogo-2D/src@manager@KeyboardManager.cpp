#include "KeyboardManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

using namespace Gerenciadores;

KeyboardManager::KeyboardManager(){};

KeyboardManager::~KeyboardManager(){
	std::cout << "KeyboardManager deconstructor" << '\n';
};

KeyboardManager *KeyboardManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == nullptr) {
    _manager = new KeyboardManager();
  }

  return _manager;
};

sf::Vector2f KeyboardManager::getJogadorUmControl() {
  sf::Vector2f control(0.0f, 0.0f);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    control.x += -1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    control.x += 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    control.y += 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    control.y -= 1;
  }

  return control;
};

sf::Vector2f KeyboardManager::getJogadorDoisControl() {
  sf::Vector2f control(0.0f, 0.0f);

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    control.x += -1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    control.x += 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    control.y += 1;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    control.y -= 1;
  }

  return control;
};

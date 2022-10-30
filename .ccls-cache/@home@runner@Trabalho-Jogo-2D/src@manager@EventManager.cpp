#include "EventManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

using namespace Gerenciadores;

EventManager::EventManager(){};

EventManager::~EventManager(){};

EventManager *EventManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == NULL) {
    _manager = new EventManager();
  }

  return _manager;
};

sf::Vector2f getJogadorUmControl() {
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
}
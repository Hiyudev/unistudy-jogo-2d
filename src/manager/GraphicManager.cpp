#include "GraphicManager.hpp"
#include "../constants/Constants.hpp"
#include <iostream>
#include <mutex>

using namespace Gerenciadores;

GraphicManager::GraphicManager() {
  this->window = new sf::RenderWindow(sf::VideoMode(200, 200), Constants::name);
};

GraphicManager::~GraphicManager(){};

GraphicManager *GraphicManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == NULL) {
    _manager = new GraphicManager();
  }

  return _manager;
};

sf::RenderWindow *GraphicManager::getWindow() { return this->window; };
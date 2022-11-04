#include "GraphicManager.hpp"
#include "../Jogo.hpp"
#include <iostream>
#include <mutex>

using namespace Gerenciadores;

GraphicManager::GraphicManager() {
  this->window = new sf::RenderWindow(sf::VideoMode(480, 320), Jogo::getNome());
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

void GraphicManager::draw(sf::Sprite* sprite)
{
	this->window->draw(*sprite);
}
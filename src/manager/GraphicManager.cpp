#include "GraphicManager.hpp"
#include "../Jogo.hpp"
#include <iostream>
#include <mutex>

using namespace Gerenciadores;

GraphicManager::GraphicManager() {
  this->window = new sf::RenderWindow(sf::VideoMode(480, 320), Jogo::getNome());
};

GraphicManager::~GraphicManager() {
  if (this->window != nullptr) {
    delete this->window;
  }
};

GraphicManager *GraphicManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == nullptr) {
    _manager = new GraphicManager();
  }

  return _manager;
};

sf::RenderWindow *GraphicManager::getWindow() { return this->window; };

void GraphicManager::draw(sf::Sprite *sprite) {
  if (sprite == nullptr) {
    std::cout << "Erro ao tentar desenhar um sprite com ponteiro nulo."
              << "\n";
    return;
  }

  this->window->draw(*sprite);
}
#include "SpriteManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>

using namespace Gerenciadores;

SpriteManager::SpriteManager(){};

SpriteManager::~SpriteManager(){};

SpriteManager *SpriteManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == NULL) {
    _manager = new SpriteManager();
  }

  return _manager;
};

sf::Sprite *SpriteManager::getSprite(std::string filePath) {
  sf::Texture *texture = new sf::Texture();
  if (!texture->loadFromFile(filePath)) {
    std::cout << "Erro ao tentar carregar imagem do diretorio: " << filePath
              << '\n';
  }

  texture->setRepeated(false);
  texture->setSmooth(false);

  sf::Sprite *sprite = new sf::Sprite();
  sprite->setTexture(*texture);

  return sprite;
};

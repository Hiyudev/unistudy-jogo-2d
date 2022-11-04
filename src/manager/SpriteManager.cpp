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
	sprite->setOrigin(8, 8);

  return sprite;
};

void SpriteManager::flipByXSprite(bool value, sf::Sprite *sprite) {
  if (value) {
    sprite->setTextureRect(sf::IntRect(16, 0, -16, 16));
  } else {
    sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
  }
};

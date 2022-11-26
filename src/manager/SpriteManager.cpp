#include "SpriteManager.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <mutex>
#include <string>

using namespace Gerenciadores;

SpriteManager::SpriteManager(){};

SpriteManager::~SpriteManager() {
  if (this->_manager != nullptr) {
    delete this->_manager;
  }
};

SpriteManager *SpriteManager::getInstance() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_manager == NULL) {
    _manager = new SpriteManager();
  }

  return _manager;
};

sf::Sprite *SpriteManager::getSprite(std::string filePath) {
	if(filePath.length() == 0)
	{
		std::cout << "Erro ao tentar carregar imagem do diretorio nulo ou vazio." << '\n';
		return nullptr;
	}
	
  sf::Texture *texture = new sf::Texture();
  if (!texture->loadFromFile(filePath)) {
    std::cout << "Erro ao tentar carregar imagem do diretorio: " << filePath
              << '\n';
		return nullptr;
  }

  texture->setRepeated(false);
  texture->setSmooth(false);

  sf::Sprite *sprite = new sf::Sprite();
  sprite->setTexture(*texture);
  sprite->setOrigin(8, 8);

  return sprite;
};
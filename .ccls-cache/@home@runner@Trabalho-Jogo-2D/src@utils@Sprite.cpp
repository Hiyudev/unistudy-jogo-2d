#include "Sprite.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Utils;

void Utils::Sprite::flipByXSprite(bool value, sf::Sprite *sprite) {
  if (sprite == nullptr) {
    std::cout << "Erro ao tentar dar um flip no sprite nulo." << '\n';
    return;
  }

  if (value) {
    sprite->setTextureRect(sf::IntRect(16, 0, -16, 16));
  } else {
    sprite->setTextureRect(sf::IntRect(0, 0, 16, 16));
  }
}
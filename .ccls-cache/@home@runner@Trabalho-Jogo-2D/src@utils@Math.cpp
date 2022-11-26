#include "Math.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace Utils;

float Math::distance(sf::Vector2f pointOne, sf::Vector2f pointTwo) {
  float x = pow((pointOne.x - pointTwo.x), 2);
  float y = pow((pointOne.y - pointTwo.y), 2);

  float dist = sqrt(x + y);

  return dist;
}

sf::Vector2f Math::Vector::sum(sf::Vector2f vectorOne, sf::Vector2f vectorTwo) {
  sf::Vector2f sum =
      sf::Vector2f(vectorOne.x + vectorTwo.x, vectorOne.y + vectorTwo.y);
  return sum;
}

sf::Vector2f Math::Vector::distance(sf::Vector2f pointOne,
                                    sf::Vector2f pointTwo) {
  sf::Vector2f dist;

  dist.x = (pointOne.x - pointTwo.x);
  dist.y = (pointOne.y - pointTwo.y);

  return dist;
}

sf::Vector2f Math::Vector::multi(sf::Vector2f vectorOne,
                                 sf::Vector2f vectorTwo) {
  sf::Vector2f res;
  res.x = vectorOne.x * vectorTwo.x;
  res.y = vectorOne.y * vectorTwo.y;

  return res;
}

sf::Vector2f Math::Vector::multi(sf::Vector2f vectorOne, float constant) {
  sf::Vector2f res;
  res.x = vectorOne.x * constant;
  res.y = vectorOne.y * constant;

  return res;
}

sf::Vector2f Math::Vector::min(sf::Vector2f vectorOne, sf::Vector2f vectorTwo) {
  bool firstIsSmall = false;

  if (vectorOne.x < vectorTwo.x && vectorOne.y < vectorTwo.y) {
    firstIsSmall = true;
  }

  if (firstIsSmall) {
    return vectorOne;
  } else {
    return vectorTwo;
  }
}
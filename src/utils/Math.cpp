#include "Math.hpp"
#include <SFML/Graphics.hpp>
#include <math.h>

using namespace Utils;

sf::Vector2f Math::v_sum(sf::Vector2f one, sf::Vector2f two) {
  sf::Vector2f sum = sf::Vector2f(one.x + two.x, one.y + two.y);
  return sum;
}

float Math::distance(sf::Vector2f pointOne, sf::Vector2f pointTwo) {
  float x = pow((pointOne.x - pointTwo.x), 2);
  float y = pow((pointOne.y - pointTwo.y), 2);

  float dist = sqrt(x + y);

  return dist;
}

sf::Vector2f Math::v_distance(sf::Vector2f pointOne, sf::Vector2f pointTwo) {
  sf::Vector2f dist;

  dist.x = (pointOne.x - pointTwo.x);
  dist.y = (pointOne.y - pointTwo.y);

  return dist;
}

sf::Vector2f Math::v_multi(sf::Vector2f vecOne, sf::Vector2f vecTwo) {
  sf::Vector2f res;
  res.x = vecOne.x * vecTwo.x;
  res.y = vecOne.y * vecTwo.y;

  return res;
}

sf::Vector2f Math::v_multi(sf::Vector2f vecOne, float constant) {
  sf::Vector2f res;
  res.x = vecOne.x * constant;
  res.y = vecOne.y * constant;

  return res;
}

sf::Vector2f Math::v_min(sf::Vector2f vecOne, sf::Vector2f vecTwo) {
  bool firstIsSmall = false;

  if (vecOne.x < vecTwo.x && vecOne.y < vecTwo.y) {
    firstIsSmall = true;
  }

  if (firstIsSmall) {
    return vecOne;
  } else {
    return vecTwo;
  }
}

sf::Vector2f Math::v_invert(sf::Vector2f vector) {
  sf::Vector2f v(-vector.x, -vector.y);

  return v;
}
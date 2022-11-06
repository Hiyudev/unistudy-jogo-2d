#include <SFML/Graphics.hpp>

namespace Utils
{
	class Math
	{
		public:
			static float distance(sf::Vector2f pointOne, sf::Vector2f pointTwo);

			static sf::Vector2f v_sum(sf::Vector2f one, sf::Vector2f two);

			static sf::Vector2f v_distance(sf::Vector2f pointOne, sf::Vector2f pointTwo);

			static sf::Vector2f v_multi(sf::Vector2f vecOne, sf::Vector2f vecTwo);
	};
}
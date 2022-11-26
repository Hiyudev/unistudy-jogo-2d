#include <SFML/Graphics.hpp>

namespace Utils
{
	class Math
	{
		public:
			static float distance(sf::Vector2f pointOne, sf::Vector2f pointTwo);

			class Vector {
				public:
					static sf::Vector2f sum(sf::Vector2f one, sf::Vector2f two);
		
					static sf::Vector2f distance(sf::Vector2f pointOne, sf::Vector2f pointTwo);
		
					static sf::Vector2f multi(sf::Vector2f vecOne, sf::Vector2f vecTwo);
					static sf::Vector2f multi(sf::Vector2f vecOne, float constant);
		
					static sf::Vector2f min(sf::Vector2f vecOne, sf::Vector2f vecTwo);
				};
	};
}
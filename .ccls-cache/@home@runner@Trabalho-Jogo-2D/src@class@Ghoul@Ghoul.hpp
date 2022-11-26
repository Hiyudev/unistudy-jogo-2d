#include <SFML/Graphics.hpp>
#include "../Inimigo/Inimigo.hpp"

using namespace Entidades::Personagens;

namespace Entidades{
  namespace Personagens{
    class Ghoul : public Inimigo
    	{
	    private:
				bool isHungry;
				sf::Clock chasingDeltaTime;
	      
	    public:
	      Ghoul(sf::Vector2f position, int patrolTiming);
				virtual ~Ghoul();

				void move();
				void patrol();
        void deal(Entidade* entidade);
	    };
  }
}

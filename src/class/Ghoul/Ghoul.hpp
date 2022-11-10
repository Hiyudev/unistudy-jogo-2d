#include <SFML/Graphics.hpp>
#include "../Inimigo/Inimigo.hpp"

using namespace Entidades::Personagens;

namespace Entidades{
  namespace Personagens{
    class Ghoul : public Inimigo
    	{
	    private:
	      
	    public:
	      Ghoul(sf::Vector2f position, int patrolTiming);
				~Ghoul();

				void patrol();
				void executar();
	    };
  }
}

#include <SFML/Graphics.hpp>
#include "../Inimigo/Inimigo.hpp"

using namespace Entidades::Personagens;

namespace Entidades{
  namespace Personagens{
    class Ceifador : public Inimigo
    	{
	    private:
	      int countDown;
	    public:
	      Ceifador(sf::Vector2f position, int patrolTiming);
				~Ceifador();

        void shoot();
				void patrol();
				void move();
				void draw();
	    };
  }
}

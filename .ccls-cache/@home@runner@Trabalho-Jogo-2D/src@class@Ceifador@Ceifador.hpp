#include <SFML/Graphics.hpp>
#include "../Inimigo/Inimigo.hpp"
#include "../Projetil/Projetil.hpp"

using namespace Entidades::Personagens;

namespace Entidades{
  namespace Personagens{
    class Ceifador : public Inimigo
    	{
	    private:
        Projetil *projetil;
	    public:
	      Ceifador(sf::Vector2f position, int patrolTiming);
				~Ceifador();

        void createProjetil(sf::Vector2f position);
        Projetil* getProjetil() const;
				void patrol();
				void move();
				void draw();
	    };
  }
}

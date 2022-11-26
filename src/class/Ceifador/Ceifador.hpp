#include <SFML/Graphics.hpp>
#include "../Inimigo/Inimigo.hpp"
#include "../Projetil/Projetil.hpp"

using namespace Entidades;
using namespace Entidades::Personagens;

namespace Entidades{
  namespace Personagens{
    class Ceifador : public Inimigo
    	{
	    private:
        Projetil *projetil;
        int countDown;
        int strength; 
	    public:
	      Ceifador(sf::Vector2f position, int patrolTiming);
				~Ceifador();

        void setProjetil(Projetil* projetil);
        Projetil* getProjetil() const;
        void deal(Entidade *entidade);
				void patrol();
				void move();
				void draw();
	    };
  }
}

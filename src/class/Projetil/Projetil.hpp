#include "../Entidade/Entidade.hpp"
#include <SFML/Graphics.hpp>

namespace Entidades{
	class Projetil : public Entidade
	{  
    private: 
      sf::Vector2f velocity;
      sf::Vector2f direction;
      
    public:
      Projetil(sf::Vector2f position = sf::Vector2f(0,0), bool flutuante = true);
      ~Projetil();

      void randDirection();
      void move();
      void draw();
      void deal(Entidade *entidade);
	};
}
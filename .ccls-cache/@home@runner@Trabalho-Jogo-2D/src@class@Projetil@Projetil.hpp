#include "../Entidade/Entidade.hpp"
#include <SFML/Graphics.hpp>

using namespace Entidades;

namespace Entidades{
	class Projetil : public Entidade
	{  
    private: 
      sf::Vector2f velocity;
    public:
      Projetil(sf::Vector2f position = sf::Vector2f(0,0), bool flutuante = true);
      ~Projetil();

      void move();
      void draw();
	};
}
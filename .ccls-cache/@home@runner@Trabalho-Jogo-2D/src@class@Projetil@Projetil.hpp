#include "../Entidade/Entidade.hpp"
#include "../Ceifador/Ceifador.hpp"
#include <SFML/Graphics.hpp>

using namespace Entidades;

namespace Entidades{
	class Projetil : public Entidade
	{  
    private: 
      Ceifador *pCeifador;
      sf::Vector2f velocity;
    public:
      Projetil(sf::Vector2f position = sf::Vector2f(0,0), Ceifador*  pCeifador = NULL);
      ~Projetil();

      void move();
	};
}
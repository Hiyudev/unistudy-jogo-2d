#include "../Entidade/Entidade.hpp"
#include <SFML/Graphics.hpp>

using namespace Entidades;

namespace Entidades{
	class Projetil : public Entidade
	{
    public:
      Projetil(sf::Vector2f position = sf::Vector2f(0,0));
      ~Projetil();
	};
}
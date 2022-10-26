#include "../Personagem/Personagem.hpp"

namespace Entidades
{
  namespace Personagens
  {
    class Jogador : public Personagem
    {
      private:
        sf::RectangleShape sprite;
        sf::Vector2f velocity;
      
      public:
        Jogador();
        ~Jogador();
    };
  }
}
#include "../Entidade/Entidade.hpp"

namespace Entidades {
  namespace Personagens {
    class Personagem : public Entidade {
      protected:
        int health;

      public:
        Personagem();
        ~Personagem();

        const int getHealth();
        void setHealth(const int health);

        void operator --();
    };
  }
}
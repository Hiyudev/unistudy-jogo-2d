#include "../Personagem/Personagem.hpp"

using namespace Entidades::Personagens;

class Inimigo : public Personagem {
	public:
		Inimigo();
		~Inimigo();

		virtual void executar();
};
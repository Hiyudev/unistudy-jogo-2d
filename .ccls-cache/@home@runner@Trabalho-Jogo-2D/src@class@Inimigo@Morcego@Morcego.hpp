#include "../Inimigo.hpp"

using namespace Entidades::Personagens;

namespace Entidades {
	namespace Personagens {
		class Morcego : public Inimigo {
			public:
				Morcego();
				~Morcego();

				void executar();
		};
	}
}
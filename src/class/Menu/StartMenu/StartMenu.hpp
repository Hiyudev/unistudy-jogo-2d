#include "../StateMenu/StateMenu.hpp"

class StartMenu : public StateMenu {
	public:
		StartMenu();
		~StartMenu();

		void generate();
		void executar();
};
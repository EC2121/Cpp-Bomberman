#include "IUpdatable.h"
#include "game.h"
Core::IUpdatable::IUpdatable()
{
	Core::Game::Subscribe_Object_To_Updatables(this);
}

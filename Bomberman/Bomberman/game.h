#pragma once
#include <memory>
#include "screen.h"
#include <vector>
#include <string>
#include "IUpdatable.h"
#include "SDL.h"

namespace Actors {
	class GameObject;
}
namespace Physics {
	class PhysicsMgr;
}

namespace Core {
	class Game {

	public:
		~Game();
		Game(const Game&) = default;
		Game& operator=(const Game&) = default;
	protected:
		Game();
	public:
		static Game& GetInstance();
		int Init();
		void Loop();
		static void Subscribe_Object_To_Drawables(Actors::GameObject* in_obj);
		static void Subscribe_Object_To_Updatables(IUpdatable* in_updatable);
	private:
		void DrawAll();
		void UpdateAll();
	public:
		std::shared_ptr<Graphics::Screen> screen;
		static std::vector<Actors::GameObject*> drawables;
		static std::vector<IUpdatable*>  updatables;
	private:
		static std::unique_ptr<Game> instance;
		SDL_Event event;
	};




}
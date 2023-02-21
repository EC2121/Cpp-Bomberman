#include "game.h"
#include "game-object.h"
#include "Player.h"	
#include "resources.h"
#include "physics-mgr.h"

namespace Core {

	std::unique_ptr<Game> Game::instance(nullptr);
	std::vector<Actors::GameObject*> Game::drawables;
	std::vector<IUpdatable*>  Game::updatables;
	Game::~Game()
	{
		for (auto object : drawables) {
			delete object;
		}

		for (auto object : updatables){
			delete object;
		}

		drawables.clear();
		updatables.clear();
	}
	Game::Game()
	{
	}
	Game& Game::Get()
	{
		if (instance == nullptr)
		{
			instance = std::make_unique<Game>(Game());
		}

		return *instance;
	}
	int Game::Init()
	{
		physics_mgr = std::make_shared<Physics::PhysicsMgr>();
		screen = std::make_shared<Graphics::Screen>(1920, 720);
		Actors::GameObject* go = new Actors::Player(Resources::Paths::GetPath("ZOMBIE"));
		return 0;
	}

	void Game::Loop()
	{
		while (true)
		{
			UpdateAll();
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT) {
					SDL_Quit();
				}
			}
			DrawAll();
		}
	}

	void Game::DrawAll()
	{
		SDL_RenderClear(screen.get()->GetRenderer());

		for (size_t x = 0; x < drawables.size(); x++) {
			drawables[x]->Draw();
		}
		SDL_RenderPresent(screen->GetRenderer());
	}

	void Game::UpdateAll()
	{
		for (size_t x = 0; x < updatables.size(); x++) {
			updatables[x]->Update();
		}
	}

	void Game::Subscribe_Object_To_Drawables(Actors::GameObject* obj)
	{
		drawables.push_back(obj);
	}

	void Game::Subscribe_Object_To_Updatables(IUpdatable* in_updatable)
	{
		updatables.push_back(in_updatable);
	}






}
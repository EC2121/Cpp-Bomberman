#include "game.h"
#include "game-object.h"
#include "Player.h"	
#include "resources.h"
#include "physics-mgr.h"
#include "Time.h"
#include "collider.h"

namespace Core {

	std::vector<Actors::GameObject*> Game::drawables;
	std::vector<IUpdatable*>  Game::updatables;
	std::unique_ptr<Game> Game::instance(nullptr);
	Game::~Game()
	{
	}
	Game::Game()
	{
	}

	Game& Game::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = std::make_unique<Game>(Game());
		}
		return *instance;
	}

	int Game::Init()
	{
		SDL_BlendMode(SDL_BLEND_MUL);
		screen = std::make_shared<Graphics::Screen>(1920, 720);
		Actors::GameObject* player = new Actors::Player(Resources::Paths::GetPath("Zombie"),Physics::KINEMATIC);
		Actors::GameObject* go2 = new Actors::GameObject(Resources::Paths::GetPath("slate"),64,64,Vector2f(100,100),Physics::STATIC);
		Time::Init();
		Physics::PhysicsMgr::GetInstance();
		return 0;
	}

	void Game::Loop()
	{
		int running = 1;
		while (running)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT) {
					running = 0;
				}
			}
			SDL_PumpEvents();
			UpdateAll();
			DrawAll();
		}
		updatables;

	}

	void Game::DrawAll()
	{
		SDL_RenderClear(screen.get()->GetRenderer());

		for (size_t x = 0; x < drawables.size(); x++) 
		{
			drawables[x]->Draw();
		}
		SDL_RenderPresent(screen->GetRenderer());
	}

	void Game::UpdateAll()
	{
		for (size_t x = 0; x < updatables.size(); x++)
		{
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
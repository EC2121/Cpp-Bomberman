#include "draw-manager.h"

namespace Drawable {

	std::vector<GameObject*> DrawManager::objects_to_render;
	std::unique_ptr<DrawManager> DrawManager:: instance;
	DrawManager::~DrawManager()
	{
	}

	DrawManager::DrawManager() {

	}
	DrawManager& DrawManager::Get()
	{
		if (instance == nullptr)
		{
			instance = std::make_unique<DrawManager>(DrawManager());
		}
		return *instance;
	}

	void DrawManager::DrawAll()
	{
	}

	void DrawManager::Subscribe_Object_To_List(GameObject* obj)
	{

		objects_to_render.push_back(obj);
	}

}

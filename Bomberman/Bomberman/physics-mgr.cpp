#include "physics-mgr.h"
#include "box-collider.h"

namespace Physics {

	std::vector<Collider*> PhysicsMgr::colliders_in_scene;
	std::unique_ptr<PhysicsMgr> PhysicsMgr::instance(nullptr);
	PhysicsMgr::~PhysicsMgr()
	{
	}

	PhysicsMgr::PhysicsMgr()
	{
	}

	void PhysicsMgr::Update()
	{
		for (size_t i = 0; i < colliders_in_scene.size(); i++)
		{
			if (colliders_in_scene[i]->type == STATIC) continue;
			for (size_t j = 0; j < colliders_in_scene.size(); j++)
			{
				if (colliders_in_scene[i] == colliders_in_scene[j] || colliders_in_scene[j]->type != STATIC) continue;
				if (colliders_in_scene[i]->CheckForCollisions(*colliders_in_scene[j]))
				{
					colliders_in_scene[i]->owner.get()->OnCollide();
				}
			}

		}
	}

	void PhysicsMgr::SubscribeToPhysicsMgr(Collider* in_collider)
	{
		colliders_in_scene.push_back(in_collider);
	}



	PhysicsMgr& PhysicsMgr::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = std::unique_ptr<PhysicsMgr>(new PhysicsMgr());
		}
		return *instance;

	}
}


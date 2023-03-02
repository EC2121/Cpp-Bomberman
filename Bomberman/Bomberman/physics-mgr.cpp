#include "physics-mgr.h"
#include "box-collider.h"
#include "game-object.h"
#include "collider.h"
#include "bm-math.h"
namespace Physics {

	std::vector<std::weak_ptr<Collider>> PhysicsMgr::colliders_in_scene;
	std::unique_ptr<PhysicsMgr> PhysicsMgr::instance(nullptr);
	int PhysicsMgr::collider_id = 0;
	PhysicsMgr::~PhysicsMgr()
	{
	}

	PhysicsMgr::PhysicsMgr()
	{
	}

	void PhysicsMgr::Update()
	{
		CollisionInfo info;
		for (size_t i = 0; i < colliders_in_scene.size(); i++)
		{
			if (colliders_in_scene[i].expired()) continue;
			if (colliders_in_scene[i].lock()->type == STATIC) continue;
			for (size_t j = 0; j < colliders_in_scene.size(); j++)
			{
				if (colliders_in_scene[j].expired()) continue;
				if (colliders_in_scene[i].lock() == colliders_in_scene[j].lock() || colliders_in_scene[j].lock()->type != STATIC) continue;
				if (colliders_in_scene[i].lock()->CheckForCollisions(*colliders_in_scene[j].lock(), info))
				{
					colliders_in_scene[i].lock()->owner.OnCollide(info);
				}
			}

		}
	}

	bool PhysicsMgr::BoxOverlap(const Vector2f in_at_pos, const int in_width, const int in_height)
	{
		Actors::GameObject temp_go = Actors::GameObject();
		BoxCollider temp = BoxCollider(temp_go,STATIC);
		temp.position = in_at_pos;
		temp.width = in_width;
		temp.heigth = in_height;
		CollisionInfo info;
		/*for (size_t i = 0; i < colliders_in_scene.size(); i++)
		{
			if (&temp == colliders_in_scene[i].get()) continue;
			if (temp.CheckForCollisions(*colliders_in_scene[i], info))
			{
				return true;
			}
		}*/
		return false;


	}

	bool PhysicsMgr::BoxOverlap(const Vector2f in_at_pos, std::vector<Actors::GameObject*>& BoxOverlap, const int in_width, const int in_height)
	{
		//std::shared_ptr<BoxCollider> temp_box = std::make_shared<BoxCollider>(nullptr, STATIC);
		/*temp_box->position = in_at_pos;
		temp_box->width = in_width;
		temp_box->heigth = in_height;
		CollisionInfo info;
		for (size_t i = 0; i < colliders_in_scene.size(); i++)
		{
			if (temp_box.get() == colliders_in_scene[i]) continue;
			if (temp_box->CheckForCollisions(*colliders_in_scene[i], info))
			{
				BoxOverlap.push_back(&colliders_in_scene[i]->owner);
			}
		}*/
		return false;
	}

	void PhysicsMgr::SubscribeToPhysicsMgr(std::shared_ptr<Collider> in_collider)
	{
		colliders_in_scene.push_back(std::shared_ptr<Collider>(in_collider));
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


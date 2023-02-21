#include "physics-mgr.h"

std::vector<Physics::Collider*> Physics::PhysicsMgr::colliders_in_scene;

Physics::PhysicsMgr::~PhysicsMgr()
{
	for (auto object : colliders_in_scene)
	{
		delete object;
	}
	colliders_in_scene.clear();
}

Physics::PhysicsMgr::PhysicsMgr()
{
}

void Physics::PhysicsMgr::Init()
{
	if (instance = nullptr)
	{
		instance = std::make_unique<PhysicsMgr>();
	}
}
void Physics::PhysicsMgr::Update()
{
	//TODO CHECK COLLISIONS
}

void Physics::PhysicsMgr::SubscribeToPhysicsMgr(Collider* in_collider)
{
	colliders_in_scene.push_back(in_collider);
}

#include "bomb.h"
#include "game.h"
#include "resources.h"
#include "physics-mgr.h"
#include "collider.h"
namespace Actors {
	Bomb::Bomb(const Vector2f in_pos)
		: GameObject(Resources::Paths::GetPath("bomb"), 100, 100, in_pos)
	{
		InsertAnimation("bomb", std::make_shared<Animations::Animation>(*this, Resources::Paths::GetPath("bomb_explosion"), 23, 1, 75, true,std::bind(&Bomb::OnBombExplosion,this)));
		ChangeCurrentAnimation("bomb");
		AttachCollider(std::make_shared<Physics::BoxCollider>(*this, Physics::KINEMATIC));
		position.x -= 25;
		position.y -= 25;
	}


	void Bomb::Update()
	{
		GameObject::Update();
		IAnimatable::Update();
	}

	void Bomb::OnBombExplosion()
	{
		std::vector<GameObject*> temp_arr;
		Physics::PhysicsMgr::BoxOverlap(position, temp_arr, 96, 96);
		for (auto a : temp_arr)
		{
			//if(a->tag == GOT_DESTROYABLE) delete a;

		}

		Destroy();
	}

}

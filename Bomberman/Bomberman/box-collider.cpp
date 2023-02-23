#include "box-collider.h"
#include "game-object.h"
#include "physics-mgr.h"

Physics::BoxCollider::BoxCollider(Actors::GameObject& in_owner)
{
	Physics::PhysicsMgr::SubscribeToPhysicsMgr(this);
	owner = std::shared_ptr<Actors::GameObject>(&in_owner);
	width = owner->width;
	heigth = owner->height;

}

Physics::BoxCollider::BoxCollider(Actors::GameObject& in_owner, const ColliderType in_type)
	:BoxCollider(in_owner)
{
	type = in_type;
}

Physics::BoxCollider::BoxCollider(Actors::GameObject& in_owner, const Vector2f in_offset, const ColliderType in_type)
	: BoxCollider(in_owner, in_type)
{
	offset = in_offset;
}

bool Physics::BoxCollider::CheckForCollisions(const Collider& in_other) const
{
	return in_other.CheckForCollisions(*this);
}

bool Physics::BoxCollider::CheckForCollisions(const BoxCollider& in_other) const
{
	if (
		position.x < in_other.position.x + in_other.width &&
		position.x + width > in_other.position.x &&
		position.y < in_other.position.y + in_other.heigth &&
		heigth + position.y > in_other.position.y
		)
	{
		return true;
	}
	return false;
}

void Physics::BoxCollider::Update()
{
	Collider::Update();
}



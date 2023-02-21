#include "box-collider.h"
#include "game-object.h"
#include "physics-mgr.h"

Physics::BoxCollider::BoxCollider(Actors::GameObject& in_owner)
{
	Physics::PhysicsMgr::SubscribeToPhysicsMgr(this);
	owner = std::make_shared<Actors::GameObject>(in_owner);
	width = owner->width;
	heigth = owner->height;

}

Physics::BoxCollider::BoxCollider(Actors::GameObject& in_owner, const Vector2i in_offset)
	: BoxCollider(in_owner)
{
	offset = in_offset;
}

bool Physics::BoxCollider::CheckForCollisions(Collider& in_other)
{
	return false;
}

bool Physics::BoxCollider::CheckForCollisions(BoxCollider& in_other)
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



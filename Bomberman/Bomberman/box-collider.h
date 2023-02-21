#pragma once
#include "collider.h"


namespace Physics {
	class BoxCollider : public Collider {
	public:
		BoxCollider() = delete;
		BoxCollider(Actors::GameObject& in_owner);
		BoxCollider(Actors::GameObject& in_owner, const Vector2i in_offset);
	
	public:
		virtual bool CheckForCollisions(Collider& in_other) override;
		virtual bool CheckForCollisions(BoxCollider& in_other) override;

	};

}


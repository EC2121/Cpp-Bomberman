#pragma once
#include "collider.h"


namespace Physics {
	class BoxCollider : public Collider {
	public:
		BoxCollider() = delete;
		BoxCollider(Actors::GameObject& in_owner);
		BoxCollider(Actors::GameObject& in_owner, const ColliderType in_type);
		BoxCollider(Actors::GameObject& in_owner, const Vector2f in_offset, const ColliderType in_type);
	
	public:
		virtual bool CheckForCollisions(const Collider& in_other) const override;
		virtual bool CheckForCollisions(const BoxCollider& in_other) const override;
		void Update() override;

	};

}


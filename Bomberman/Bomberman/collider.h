#pragma once
#include <memory>
#include "bm-math.h"
#include "game-object.h"

namespace Physics {
	enum ColliderType
	{
		STATIC,
		KINEMATIC
	};
	class BoxCollider;
	class Collider : public Core::IUpdatable {
	public:

		~Collider() {};
		Collider(const Collider&) = default;
		Collider& operator =(const Collider&) = default;
		Collider()
			: owner(nullptr)
			, position(Vector2f())
			, width(0)
			, heigth(0)
			, offset(Vector2f())
			, type(STATIC)
		{};
	protected:

	public:
		virtual bool CheckForCollisions(const Collider& in_other) const = 0;
		virtual bool CheckForCollisions(const BoxCollider& in_other)const  = 0;
		void Update() override;
	public:
		std::shared_ptr<Actors::GameObject> owner;
		ColliderType type;
		Vector2f position;
		int width;
		int heigth;
		Vector2f offset;
	};
}
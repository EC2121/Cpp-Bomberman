#pragma once
#include <memory>
#include "bm-math.h"
#include "game-object.h"

namespace Physics {
	class BoxCollider;
	class Collider : public Core::IUpdatable {
	public:
		Collider()
			: owner(nullptr)
			, position(Vector2i())
			, width(0)
			, heigth(0)
			, offset(Vector2i())
		{};
		~Collider() {};
		Collider(const Collider&) = default;
		Collider& operator =(const Collider&) = default;

	public:
		virtual bool CheckForCollisions(Collider& in_other) = 0;
		virtual bool CheckForCollisions(BoxCollider& in_other) = 0;
		void Update() override;
	public:
		std::shared_ptr<Actors::GameObject> owner;
		Vector2i position;
		int width;
		int heigth;
		Vector2i offset;
	};
}
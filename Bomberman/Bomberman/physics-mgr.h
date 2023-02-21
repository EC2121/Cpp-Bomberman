#pragma once
#include <memory>
#include "IUpdatable.h"
#include <vector>

namespace Physics {
	class Collider;
	class PhysicsMgr : public Core::IUpdatable {
	public:
		~PhysicsMgr();
		PhysicsMgr(const PhysicsMgr&) = default;
		PhysicsMgr& operator=(const PhysicsMgr&) = delete;
		PhysicsMgr();
	private:

	public:
		void Init();
		void Update() override;
		static void SubscribeToPhysicsMgr(Collider* in_collider);
	private:
		static std::vector<Collider*> colliders_in_scene;
		std::unique_ptr<PhysicsMgr> instance;
	};
}
#pragma once
#include <memory>
#include "IUpdatable.h"
#include <vector>

namespace Physics {
	class Collider;
	class PhysicsMgr : public Core::IUpdatable {
	public:
		PhysicsMgr(const PhysicsMgr&) = default;
		PhysicsMgr& operator=(const PhysicsMgr&) = default;
		~PhysicsMgr();
	protected:
		PhysicsMgr();

	public:
		void Update() override;
		static void SubscribeToPhysicsMgr(Collider* in_collider);
		static PhysicsMgr& GetInstance();
		static std::vector<Collider*> colliders_in_scene;
	private:
		static std::unique_ptr<PhysicsMgr> instance;
	};
}
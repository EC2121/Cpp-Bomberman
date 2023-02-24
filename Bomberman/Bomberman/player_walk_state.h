#pragma once
#include "state.h"

namespace FSM {
	class PlayerWalkState : public State {
		// Inherited via State
	public:
		PlayerWalkState() = default;
		virtual void OnEnter(Actors::GameObject& owner) override;
		virtual void OnExit(Actors::GameObject& owner) override;
		virtual void Update(Actors::GameObject& owner) override;
	};
}
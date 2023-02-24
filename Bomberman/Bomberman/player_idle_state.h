#pragma once
#include "state.h"

namespace FSM {
	class PlayerIdleState : public State {
		// Inherited via State
	public :
		PlayerIdleState() = default;
		virtual void OnEnter(Actors::GameObject& owner) override;
		virtual void OnExit(Actors::GameObject& owner) override;
		virtual void Update(Actors::GameObject& owner) override;
	};
}
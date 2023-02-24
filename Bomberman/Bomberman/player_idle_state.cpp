#include "player_idle_state.h"
#include "game-object.h"
#include "player.h"
void FSM::PlayerIdleState::OnEnter(Actors::GameObject& owner)
{
	owner.ChangeCurrAnimation("idle");
}

void FSM::PlayerIdleState::OnExit(Actors::GameObject& owner)
{
}

void FSM::PlayerIdleState::Update(Actors::GameObject& owner)
{
	if (((Actors::Player&)owner).CheckForMovementInputs()) {
		owner.ChangeCurrentState(WALK);
	}

}

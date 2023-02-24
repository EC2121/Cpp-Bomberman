#include "player_walk_state.h"
#include "game-object.h"
#include "player.h"
void FSM::PlayerWalkState::OnEnter(Actors::GameObject& owner)
{
	owner.ChangeCurrAnimation("walk");
}

void FSM::PlayerWalkState::OnExit(Actors::GameObject& owner)
{
}

void FSM::PlayerWalkState::Update(Actors::GameObject& owner)
{
	if (!((Actors::Player&)owner).CheckForMovementInputs())
	{
		owner.ChangeCurrentState(IDLE);
	}
}

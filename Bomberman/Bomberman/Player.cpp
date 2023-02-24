#include "player.h"
#include <iostream>
#include "time.h"
#include "SDL.h"
#include "box-collider.h"
#include "resources.h"
#include "player_FSM_include.h"
#define PLAYER_SPEED 100.f

Actors::Player::Player(std::string in_path, const Physics::ColliderType in_collider_type)
	: GameObject(in_path, in_collider_type)

{
	Init();
}

Actors::Player::Player(std::string in_path, const int in_width, const int in_height, const Vector2f in_pos , const Physics::ColliderType in_collider_type)
	: GameObject(in_path, in_width, in_height, in_pos,in_collider_type)
{
	Init();
}

bool Actors::Player::CheckForMovementInputs()
{
	auto* keys = SDL_GetKeyboardState(nullptr);
	if (keys[SDL_SCANCODE_D])
	{
		velocity.x = 1;
	}
	else if (keys[SDL_SCANCODE_A]) 
	{
		velocity.x = -1;
	}
	if (keys[SDL_SCANCODE_W])
	{
		velocity.y = -1;
	}
	else if (keys[SDL_SCANCODE_S])
	{
		velocity.y = 1;
	}
	return velocity.Magnitude() > 0;
}

void Actors::Player::Init()
{
	speed = PLAYER_SPEED;
	std::shared_ptr<Animations::Animation> walk_anim =
		std::make_shared<Animations::Animation>(*this, Resources::Paths::GetPath("zombiesp"), 4, 1, 100);
	std::shared_ptr<Animations::Animation> idle_anim =
		std::make_shared<Animations::Animation>(*this, Resources::Paths::GetPath("zombie"), 1, 1, 100);

	InsertAnimation("walk", walk_anim);
	InsertAnimation("idle", idle_anim);
	ChangeCurrAnimation("idle");


	states_map[FSM::IDLE] = std::make_shared<FSM::PlayerIdleState>();
	states_map[FSM::WALK] = std::make_shared<FSM::PlayerWalkState>();
	curr_state = states_map[FSM::IDLE];
}

void Actors::Player::OnCollide()
{
	position += (-velocity) * speed * Core::Time::GetDeltatime();
}

void Actors::Player::Update()
{

	velocity = Vector2f::zero;
	GameObject::Update();
	if (curr_state != nullptr) {
		curr_state->Update(*this);
	}
	position += velocity * speed * Core::Time::GetDeltatime();

}

#include "player.h"
#include <iostream>
#include "time.h"
#include "SDL.h"
#include "box-collider.h"
#define PLAYER_SPEED 50.f

Actors::Player::Player(std::string in_path, const Physics::ColliderType in_collider_type)
	: GameObject(in_path, in_collider_type)
{
	speed = PLAYER_SPEED;
}

Actors::Player::Player(std::string in_path, const int in_width, const int in_height, const Vector2f in_pos , const Physics::ColliderType in_collider_type)
	: GameObject(in_path, in_width, in_height, in_pos,in_collider_type)
{
}

void Actors::Player::OnCollide()
{
	position += (-velocity) * speed * Core::Time::GetDeltatime();
}

void Actors::Player::Update()
{

	velocity = Vector2f::zero;
	GameObject::Update();
	auto* keys = SDL_GetKeyboardState(nullptr);
	if (keys[SDL_SCANCODE_D]) velocity.x = 1;
	else if (keys[SDL_SCANCODE_A]) velocity.x = -1;
	if (keys[SDL_SCANCODE_W]) velocity.y = -1;
	else if (keys[SDL_SCANCODE_S]) velocity.y = 1;


	position += velocity * speed * Core::Time::GetDeltatime();

}

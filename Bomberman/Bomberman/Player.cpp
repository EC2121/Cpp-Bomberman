#include "Player.h"
#include <iostream>
Actors::Player::Player(std::string in_path)
	:GameObject(in_path)
{
}

Actors::Player::Player(std::string in_path, const int in_width, const int in_height, const Vector2i in_pos)
	: GameObject(in_path, in_width, in_height, in_pos)
{
}

void Actors::Player::Update()
{
	std::cout << "IM A PLAYER";
}

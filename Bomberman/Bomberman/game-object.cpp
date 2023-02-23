#include "game-object.h"
#include "SDL_Image.h"
#include "game.h"
#include <stdlib.h>
#include "box-collider.h"
#include <iostream>
namespace Actors {
	GameObject::GameObject()
		: width(0)
		, height(0)
		, position(Vector2f())
	{

	}

	GameObject::GameObject(std::string in_path, const Physics::ColliderType in_type)
		: GameObject()
	{
		Core::Game::Subscribe_Object_To_Drawables(this);
		SDL_Surface* surface = IMG_Load(in_path.c_str());
		if (surface == nullptr)
		{
			error_type = GOET_FAILED_TO_READ_IMAGE;
			std::cout << error_type << "Failed to create read image";
			return;
		}
		width = surface->w;
		height = surface->h;
		texture = std::make_shared<SDL_Texture*>(SDL_CreateTextureFromSurface(Core::Game::GetInstance().screen->GetRenderer(), surface));
		if (texture == nullptr)
		{
			error_type = GOET_FAILED_TO_CREATE_TEXTURE;
			std::cout << error_type << "Failed to create texture for GameObject";
			return;
		}
		rect = std::make_shared<SDL_Rect>();
		rect->w = width;
		rect->h = height;
		rect->x = 0;
		rect->y = 0;
		velocity = Vector2f::zero;
		own_collider = std::make_shared<Physics::BoxCollider>(*this, in_type);
	}

	GameObject::GameObject(std::string in_path, const int in_width, const int in_height, Vector2f in_pos, const Physics::ColliderType in_type)
		: GameObject(in_path, in_type)
	{
		position = in_pos;
		width = in_width;
		height = in_height;
		rect->w = width;
		rect->h = height;
		own_collider->heigth = height;
		own_collider->width = width;
		own_collider->position = position;

	}


	GameObject::~GameObject()
	{
	}
	void GameObject::Draw()
	{
		SDL_RenderCopy(Core::Game::GetInstance().screen->GetRenderer(), *texture, nullptr, rect.get());
	}
	void GameObject::Update()
	{
		rect->x = position.x;
		rect->y = position.y;
	}
}



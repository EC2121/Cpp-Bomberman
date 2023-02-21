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
		, position(Vector2i())
	{

	}

	GameObject::GameObject(std::string in_path)
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
		texture = std::make_shared<SDL_Texture*>(SDL_CreateTextureFromSurface(Core::Game::Get().screen->GetRenderer(), surface));
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
		own_collider = std::make_shared<Physics::BoxCollider>(*this);
	}

	GameObject::GameObject(std::string in_path, const int in_width, const int in_height, Vector2i in_pos)
		: GameObject(in_path)
	{
		position = in_pos;
		width = in_width;
		height = in_height;
		rect->w = width;
		rect->h = height;
	}


	GameObject::~GameObject()
	{
	}
	void GameObject::Draw()
	{
		SDL_RenderCopy(Core::Game::Get().screen->GetRenderer(), *texture, nullptr, rect.get());
	}
	void GameObject::Update()
	{
	}
}



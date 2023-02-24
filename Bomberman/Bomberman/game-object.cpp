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
		, curr_animation(nullptr)
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
		dstrect = std::make_shared<SDL_Rect>();
		srcrect = std::make_shared<SDL_Rect>();
		srcrect->w = width;
		srcrect->h = height;
		srcrect->x = 0;
		srcrect->x = 0;
		dstrect->w = width;
		dstrect->h = height;
		dstrect->x = 0;
		dstrect->y = 0;
		velocity = Vector2f::zero;
		own_collider = std::make_shared<Physics::BoxCollider>(*this, in_type);
	}

	GameObject::GameObject(std::string in_path, const int in_width, const int in_height, Vector2f in_pos, const Physics::ColliderType in_type)
		: GameObject(in_path, in_type)
	{
		position = in_pos;
		width = in_width;
		height = in_height;
		dstrect->w = width;
		dstrect->h = height;

		own_collider->heigth = height;
		own_collider->width = width;
		own_collider->position = position;
	}


	GameObject::~GameObject()
	{
	}
	void GameObject::ChangeCurrentState(const FSM::States in_new_state)
	{
		curr_state->OnExit(*this);
		curr_state = states_map[in_new_state];
		curr_state->OnEnter(*this);
	}
	void GameObject::InsertAnimation(std::string in_key, std::shared_ptr<Animations::Animation> in_anim)
	{
		animations_map[in_key] = in_anim;
		curr_animation = in_anim;
	}
	void GameObject::ChangeCurrAnimation(std::string in_new_anim_key)
	{
		if (curr_animation == nullptr) {
			return;

		}

		curr_animation->Stop();
		curr_animation->Reset();
		curr_animation = animations_map[in_new_anim_key];
		curr_animation->Play();
	}
	void GameObject::ChangeSprite(const std::shared_ptr<SDL_Texture*> in_new_texture, const int in_x, const int in_y, const int in_width, const int in_height)
	{
		srcrect.get()->x = in_x;
		srcrect.get()->y = in_y;
		srcrect.get()->w = in_width;
		srcrect.get()->h = in_height;
		texture = in_new_texture;
	}
	void GameObject::Draw()
	{
		SDL_RenderCopy(Core::Game::GetInstance().screen->GetRenderer(), *texture, srcrect.get(), dstrect.get());
	}
	void GameObject::Update()
	{
		dstrect->x = position.x;
		dstrect->y = position.y;
	}
}



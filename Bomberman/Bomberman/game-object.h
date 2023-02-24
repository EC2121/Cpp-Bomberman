#pragma once
#include "SDL.h"
#include <memory>
#include <string>
#include "bm-math.h"
#include "IUpdatable.h"
#include "animation.h"
#include "state.h"
#include <map>
namespace Physics {
	class Collider;
	enum ColliderType;
}

namespace Actors {

	enum GameObjectErrorType
	{
		GOET_NONE,
		GOET_FAILED_TO_READ_IMAGE,
		GOET_FAILED_TO_CREATE_TEXTURE,
		GOET_MAX
	};


	class GameObject : public Core::IUpdatable {
	public:
		GameObject();
		GameObject(std::string in_path, const Physics::ColliderType in_type);
		GameObject(std::string in_path, const int in_width, const int in_height, const Vector2f in_pos, const Physics::ColliderType in_type);
		~GameObject();
	public:
		void ChangeCurrentState(const FSM::States in_new_state);
		void InsertAnimation(std::string in_key, std::shared_ptr<Animations::Animation> in_anim);
		void ChangeCurrAnimation(std::string in_new_anim_key);
		Vector2f GetPosition() const { return position; };
		void ChangeSprite(const std::shared_ptr<SDL_Texture*> in_new_texture, const int in_x, const int in_y, const int in_width, const int in_height);
		virtual void OnCollide() {};
		void Draw();
		void Update() override;


	public:
		int width;
		int height;
	protected:
		std::shared_ptr<FSM::State> curr_state;
		std::map<FSM::States, std::shared_ptr<FSM::State>> states_map;
		GameObjectErrorType error_type = GOET_NONE;
		std::shared_ptr<Animations::Animation> curr_animation;
		std::map<std::string, std::shared_ptr<Animations::Animation>> animations_map;
		std::shared_ptr<SDL_Rect> dstrect;
		std::shared_ptr<SDL_Rect> srcrect;
		std::shared_ptr<SDL_Texture*> texture;
		Vector2f position;
		Vector2f velocity;
		std::shared_ptr<Physics::Collider> own_collider;



	};



}



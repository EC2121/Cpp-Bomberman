#pragma once
#include "SDL.h"
#include <memory>
#include <string>
#include "bm-math.h"
#include "IUpdatable.h"
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
	class GameObject : public Core::IUpdatable{
	public:
		GameObject();
		GameObject(std::string in_path, const Physics::ColliderType in_type);
		GameObject(std::string in_path, const int in_width, const int in_height, const Vector2f in_pos, const Physics::ColliderType in_type);
		~GameObject();
	public:
		Vector2f GetPosition() const { return position; };
		virtual void OnCollide() {};
		void Draw();
		void Update() override;


	public:
		int width;
		int height;
	protected:
		GameObjectErrorType error_type = GOET_NONE;
		std::shared_ptr<SDL_Rect> rect;
		std::shared_ptr<SDL_Texture*> texture;
		Vector2f position;
		Vector2f velocity;
		std::shared_ptr<Physics::Collider> own_collider;



	};



}



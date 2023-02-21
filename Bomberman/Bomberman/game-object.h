#pragma once
#include "SDL.h"
#include <memory>
#include <string>
#include "bm-math.h"
#include "IUpdatable.h"
namespace Physics {
	class Collider;
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
		GameObject(std::string in_path);
		GameObject(std::string in_path,const int in_width, const int in_height, Vector2i in_pos);
		~GameObject();
	public:
		const Vector2i GetPosition() const { return position; };
		void Draw();
		void Update() override;


	public:
		int width;
		int height;
	private:
		GameObjectErrorType error_type = GOET_NONE;
		std::shared_ptr<SDL_Rect> rect;
		std::shared_ptr<SDL_Texture*> texture;
		Vector2i position;
		std::shared_ptr<Physics::Collider> own_collider;



	};



}



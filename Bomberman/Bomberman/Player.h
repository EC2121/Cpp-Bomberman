#pragma once
#include "game-object.h"
#include "bm-math.h"


namespace Actors {

	class Player : public GameObject {


	public:
		Player() = delete;
		Player(std::string in_path, const Physics::ColliderType in_collider_type);
		Player(std::string in_path, const int in_width, const int in_height, const Vector2f in_pos, const Physics::ColliderType in_collider_type);
		Player(const Player&) = default;
		Player& operator=(const Player&) = delete;

	public:
		bool CheckForMovementInputs();
		void Init();
		void OnCollide() override;
		void Update() override;


	protected:
		float speed;
	};
}
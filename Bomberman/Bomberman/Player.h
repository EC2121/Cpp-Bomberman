#pragma once
#include "game-object.h"
#include "bm-math.h"
namespace Actors {
	class Player : public GameObject {
	public:
		Player() = delete;
		Player(std::string in_path);
		Player(std::string in_path, const int in_width, const int in_height, const Vector2i in_pos);
		Player(const Player&) = default;
		Player& operator=(const Player&) = delete;

		void Update() override;

	};
}
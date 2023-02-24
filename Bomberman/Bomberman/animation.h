#pragma once
#include <string>
#include "IUpdatable.h"
#include "SDL.h"
#include <memory>
namespace Actors {
	class GameObject;
}
namespace Animations {
	enum AnimErrorType {
		AET_FAILED_TO_READ_IMAGE
	};

	class Animation : public Core::IUpdatable {

	public:
		Animation() = delete;
		Animation(Actors::GameObject& in_owner, std::string in_path, const int in_number_of_frames_per_row,
			const int in_number_of_frames_per_column, const float in_frame_rate_in_ms);
	public:
		void Play() { is_playing = true; };
		void Stop() { is_playing = false; };
		void Update() override;
		void Reset();
	private:
		AnimErrorType error_type = AET_FAILED_TO_READ_IMAGE;
		std::shared_ptr<SDL_Texture*> anim_texture;
		Actors::GameObject& owner;
		bool is_playing;
		int width;
		int height;
		int number_of_frames_per_row;
		int number_of_frames_per_column;
		int frame_rate_in_ms;
		Uint32 ticks;
		Uint32 time;
	};
}
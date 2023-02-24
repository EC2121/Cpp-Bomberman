#include "animation.h"
#include "game-object.h"
#include "SDL_image.h"
#include <iostream>
#include "game.h"
namespace Animations {
	Animation::Animation(Actors::GameObject& in_owner, std::string in_path, const int in_number_of_frames_per_row, const int in_number_of_frames_per_column, const float in_frame_rate_in_ms)
		: owner(in_owner)
	{

		SDL_Surface* surface = IMG_Load(in_path.c_str());
		if (surface == nullptr)
		{
			error_type = AET_FAILED_TO_READ_IMAGE;
			std::cout << error_type << "Failed to create read image";
			return;
		}
		width = surface->w / in_number_of_frames_per_row;
		height = surface->h / in_number_of_frames_per_column;
		anim_texture = std::make_shared<SDL_Texture*>(SDL_CreateTextureFromSurface(Core::Game::GetInstance().screen->GetRenderer(), surface));
		is_playing = false;
		number_of_frames_per_row = in_number_of_frames_per_row;
		number_of_frames_per_column = in_number_of_frames_per_column;
		frame_rate_in_ms = in_frame_rate_in_ms;

	}

	void Animation::Update()
	{
		if (is_playing)
		{
			ticks = SDL_GetTicks();
			time = ticks / frame_rate_in_ms;
			Uint32 x = width * (time % number_of_frames_per_row);
			owner.ChangeSprite(anim_texture,x, 0, width, height);
		}
	}
	void Animation::Reset()
	{
		ticks = 0;
		time = 0;
	}
}



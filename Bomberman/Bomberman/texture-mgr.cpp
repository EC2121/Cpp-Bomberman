#include "texture-mgr.h"
#include <stdlib.h>
#include <SDL_image.h>
#include <iostream>
#include "game.h"
namespace Graphics {

	TextureMgrErrorType TextureMgr::error_type;
	std::map<std::string, std::shared_ptr<SDL_Texture*>> TextureMgr::texture_map;
	void TextureMgr::InsertTexture(std::string in_key, std::string in_path)
	{

		SDL_Surface* surface = IMG_Load(in_path.c_str());
		if (surface == nullptr)
		{
			error_type = TMET_FAILED_TO_READ_IMAGE;
			std::cout << error_type << "Failed to create read image";
			return;
		}
		texture_map[in_key] = std::make_shared<SDL_Texture*>(SDL_CreateTextureFromSurface(Core::Game::GetInstance().screen->GetRenderer(), surface));
	}
	std::shared_ptr<SDL_Texture*> TextureMgr::GetTexture(std::string in_key)
	{


		return texture_map[in_key];
	}
}


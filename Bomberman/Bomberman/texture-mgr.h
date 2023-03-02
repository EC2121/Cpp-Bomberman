#pragma once
#include <map>
#include <string>
#include <SDL.h>
#include <memory>
namespace Graphics {
	enum TextureMgrErrorType
	{
		TMET_NONE,
		TMET_FAILED_TO_READ_IMAGE
	};
	class TextureMgr {
	public:
		static void InsertTexture(std::string in_key,std::string in_path);
		static std::shared_ptr<SDL_Texture*> GetTexture(std::string in_key);
	private:
		static TextureMgrErrorType error_type;
		static std::map<std::string, std::shared_ptr<SDL_Texture*>> texture_map;
	};
}

#pragma once
#include <map>
#include <string>

#define ADD_TO_RESOURCES_PATHS(key,value) resources_paths[key] = value;
namespace Resources {
	class Paths {

	public:
		static std::string GetPath(std::string in_key);
	private:
		static inline std::map<std::string, std::string> resources_paths =
		{
			{"zombie", "resources\\zombie.png"},
			{"zombie2", "resources\\spr_zombie_charge.png"},
			{"slate", "resources\\slate_64x64.png"},
			{"zombiesp", "resources\\zombie-walk.png"}


		};


	};
	

}
//static std::map<std::string, std::string> resources_paths = std::map<std::string, std::string>();

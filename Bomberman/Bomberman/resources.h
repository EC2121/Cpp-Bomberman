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
			{"zombie", "resources\\spr_zombie_idle.png"},
			{"zombie", "resources\\spr_zombie_idle.png"}
		};


	};
	

}
//static std::map<std::string, std::string> resources_paths = std::map<std::string, std::string>();

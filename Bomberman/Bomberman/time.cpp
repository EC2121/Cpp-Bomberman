#include "Time.h"
#include "SDL.h"
#include <iostream>

namespace Core {
	float Time::deltatime;
	std::unique_ptr<Time> Time::instance;
	float Time::now;
	float Time::last;
	Time::Time()
	{
	}
	void Time::Init()
	{
		if (instance == nullptr)
		{
			instance = std::unique_ptr<Time>(new Time());
		}
	}
	void Time::Update()
	{
		Time::now = SDL_GetTicks();
		Time::deltatime = (now - last) / 1000.f;
		Time::last = now;


	}

}
#define SDL_MAIN_HANDLED
#define _CRT_SECURE_NO_WARNINGS
#include "SDL.h"
#include "game.h"
#include <fstream>
#include <string>
#include "resources.h"
#include <iostream>
int main(int argc, char** argv)
{
	using namespace Core;
	Game::Get().Init();
	Game::Get().Loop();

}
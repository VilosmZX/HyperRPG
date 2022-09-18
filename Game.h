#include <string>
typedef unsigned int uint;
#pragma once

#include <SDL.h>
#include <cstdio>
#include <cstdlib>

class Game
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* playerTex = nullptr;
	SDL_Event ev;
	const uint FPS;
	bool running = true;

public:
	Game(std::string title, uint width, uint height, const uint FPS);
	void init();
	void loop();
	void events();
	void kill();
	void render();
};


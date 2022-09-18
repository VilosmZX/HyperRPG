#include "Game.h"
#include <SDL_image.h>
#include "Utils.h"

Game::Game(std::string title, uint width, uint height, const uint FPS)
	: FPS { FPS }
{
	window = SDL_CreateWindow(
		title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width,
		height,
		SDL_WINDOW_SHOWN
	);
	renderer = SDL_CreateRenderer(window, -1, 0);

	if (window == nullptr)
	{
		printf("Ada error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if (renderer == nullptr)
	{
		printf("Ada error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}

void Game::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Init Error: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	playerTex = utils::loadTexture(renderer, "res/player.png");
}

void Game::render()
{
	SDL_RenderCopy(renderer, playerTex, NULL, NULL);
}

void Game::events()
{
	while (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			this->running = false;
			break;
		}
	}
}

void Game::loop()
{
	while (this->running)
	{
		Uint32 start = SDL_GetTicks();
		this->events();

		SDL_RenderClear(renderer);

		this->render();

		SDL_RenderPresent(renderer);

		Uint32 end = SDL_GetTicks();
		Uint32 elapsed = (end - start);

		if ((1000 / FPS) > elapsed)
		{
			SDL_Delay((1000 / FPS) - elapsed);
		}
	}
	this->kill();
}

void Game::kill()
{
	SDL_DestroyWindow(this->window);
}
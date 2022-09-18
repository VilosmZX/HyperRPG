#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>


namespace utils
{
	SDL_Texture* loadTexture(SDL_Renderer* renderer, std::string path);
}

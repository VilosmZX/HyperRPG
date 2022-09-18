#include "Utils.h"

SDL_Texture* utils::loadTexture(SDL_Renderer* renderer, std::string path)
{
	SDL_Surface* tmpSurface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return texture;
}
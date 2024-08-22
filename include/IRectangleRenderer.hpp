#pragma once
#include "SDL.h"

class IRectangleRenderer
{
	virtual void render(SDL_Renderer* gameRenderer, int x, int y, int width, int height, SDL_Color color) = 0; 
};
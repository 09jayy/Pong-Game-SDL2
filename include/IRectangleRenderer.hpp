#pragma once
#include "SDL.h"

class IRectangleRenderer
{
public:
	virtual void render(SDL_Renderer* gameRenderer, int x, int y, int width, int height, SDL_Color color) = 0; 
	virtual ~IRectangleRenderer() {}; 
};
#pragma once
#include "SDL.h"
#include "Entity.hpp"

class IRenderer
{
public:
	virtual ~IRenderer() {}

	virtual void render(SDL_Renderer* renderer, Entity* entity) = 0; 
};
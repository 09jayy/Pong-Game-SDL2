#pragma once
#include "SDL.h"

class ICircleRenderer
{
public:
	virtual void render(SDL_Renderer* gameRenderer, int32_t centerX, int32_t centerY, int32_t radius) = 0;
	virtual ~ICircleRenderer() {};
};
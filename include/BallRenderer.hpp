#pragma once
#include "ICircleRenderer.hpp"

class BallRenderer : public ICircleRenderer
{
public:
	BallRenderer() = default;
	void render(SDL_Renderer* gameRenderer, int32_t centerX, int32_t centerY, int32_t radius); 
};
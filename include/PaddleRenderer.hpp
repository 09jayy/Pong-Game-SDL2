#pragma once
#include "IRectangleRenderer.hpp"

class PaddleRenderer : public IRectangleRenderer
{
private:
	SDL_Rect rect;

public:
	PaddleRenderer(); 

	void render(SDL_Renderer* gameRenderer, int x, int y, int width, int height, SDL_Color color) override;
};
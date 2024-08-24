#include <iostream>
#include "PaddleRenderer.hpp"

PaddleRenderer::PaddleRenderer() : rect({0,0,0,0}){};

void PaddleRenderer::render(SDL_Renderer* gameRenderer, int x, int y, int width, int height, SDL_Color color)
{
	rect = { x,y,width,height };
	SDL_SetRenderDrawColor(gameRenderer, color.r, color.b, color.g, color.a);
	SDL_RenderDrawRect(gameRenderer, &rect);
}; 
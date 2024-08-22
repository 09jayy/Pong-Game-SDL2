#include "PaddleRenderer.hpp"

void PaddleRenderer::render(SDL_Renderer* gameRenderer, int x, int y, int width, int height, SDL_Color color) override
{
	rect = { x,y,width,height };
	SDL_SetRenderDrawColor(gameRenderer, color.r, color.b, color.g, color.a);
	SDL_RenderDrawRect(gameRenderer, &rect);
}
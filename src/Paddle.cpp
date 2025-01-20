#include <iostream>
#include "Paddle.hpp"
#include "Game.hpp"

Paddle::Paddle(int xPos, int yPos, int width, int height, SDL_Scancode upKey, SDL_Scancode downKey)
	: Entity(xPos, yPos), Rect(width,height), color(SDL_Color({ 255,255,255,255 })), upKey(upKey), downKey(downKey)
{};

void Paddle::processInput(const Uint8* keyboardState)
{
	const int STEP_SIZE = 20; 
	if (keyboardState[upKey])
	{
		yPos = (yPos - STEP_SIZE >= 0) ? yPos - STEP_SIZE: 0;

	}
	if (keyboardState[downKey])
	{
		yPos = (yPos + STEP_SIZE <= Game::GET_HEIGHT() - height) ? yPos + STEP_SIZE: Game::GET_HEIGHT() - height;
	}
}; 

void Paddle::render(SDL_Renderer* gameRenderer)
{
	SDL_Rect rect = { xPos,yPos,width,height };
	SDL_SetRenderDrawColor(gameRenderer, color.r, color.b, color.g, color.a);
	SDL_RenderDrawRect(gameRenderer, &rect);
};
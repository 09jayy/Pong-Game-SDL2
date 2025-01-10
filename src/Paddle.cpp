#include <iostream>
#include "Paddle.hpp"
#include "Game.hpp"

Paddle::Paddle(int xPos, int yPos, int width, int height, SDL_Scancode upKey, SDL_Scancode downKey)
	: Entity(xPos, yPos), width(width), height(height), color(SDL_Color({ 255,255,255,255 })), upKey(upKey), downKey(downKey)
{};

void Paddle::move()
{
};

void Paddle::processInput(const Uint8* keyboardState)
{
	if (xPos == 150)
	{
		std::cout << yPos << std::endl;
		std::cout << "height " << Game::GET_HEIGHT() - width << std::endl;
	}
	if (keyboardState[upKey])
	{
		yPos = (yPos - 10 >= 0) ? yPos - 10 : 0;

	}
	if (keyboardState[downKey])
	{
		yPos = (yPos + 10 <= Game::GET_HEIGHT() - height) ? yPos + 10 : Game::GET_HEIGHT() - height;
	}
}; 

void Paddle::render(SDL_Renderer* gameRenderer)
{
	SDL_Rect rect = { xPos,yPos,width,height };
	SDL_SetRenderDrawColor(gameRenderer, color.r, color.b, color.g, color.a);
	SDL_RenderDrawRect(gameRenderer, &rect);
};
#include <iostream>
#include "Paddle.hpp"

Paddle::Paddle(int x, int y, int width, int height)
	: Entity(x, y), width(width), height(height), color(SDL_Color({ 255,255,255,255 })), renderer(nullptr)
{};

void Paddle::setRenderer(std::shared_ptr<IRectangleRenderer> renderer)
{
	this->renderer = renderer;
};

void Paddle::render(SDL_Renderer* gameRenderer)
{
	renderer->render(gameRenderer,x, y, width, height, color);
};
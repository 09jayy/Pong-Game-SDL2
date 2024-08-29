#include <iostream>
#include "Paddle.hpp"

Paddle::Paddle(int x, int y, int width, int height)
	: Entity(x, y), width(width), height(height), color(SDL_Color({ 255,255,255,255 })), renderer(nullptr), controller(nullptr)
{};

void Paddle::setController(std::unique_ptr<IMoveableY> newController)
{
	controller = std::move(newController); 
};

void Paddle::addVelocity(float add)
{
	controller->adjustVelocity(add);
	controller->move(y); 
};

void Paddle::killVelocity()
{
	controller->killVelocity(); 
};

void Paddle::move()
{
	controller->move(y);
	y = (y < 0) ? 0 : y;
	y = (y + height > 720) ? 720 - height: y; 
}

void Paddle::setRenderer(std::shared_ptr<IRectangleRenderer> renderer)
{
	this->renderer = renderer;
};

void Paddle::render(SDL_Renderer* gameRenderer)
{
	renderer->render(gameRenderer,x, y, width, height, color);
};
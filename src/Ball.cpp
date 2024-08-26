#include "Ball.hpp"

Ball::Ball() :Entity(), radius(0), renderer(nullptr), color({ 255,255,255,255 }) {}; 
Ball::Ball(int x, int y, int radius) : Entity(x, y), radius(radius), color({ 255,255,255,255 }) {};

void Ball::setRenderer(std::unique_ptr<ICircleRenderer> renderer)
{
	this->renderer = std::move(renderer); 
};

void Ball::render(SDL_Renderer* gameRenderer)
{
	renderer->render(gameRenderer, x, y, radius); 
}; 
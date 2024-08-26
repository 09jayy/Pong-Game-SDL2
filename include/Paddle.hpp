#pragma once
#include <iostream>
#include <memory>
#include "SDL.h"
#include "Entity.hpp"
#include "IRectangleRenderer.hpp"

class Paddle : public Entity
{
private:
	int width, height;
	std::shared_ptr<IRectangleRenderer> renderer;
	SDL_Color color; 
public:	
	Paddle() = default;
	Paddle(int x, int y, int width, int height);

	void setRenderer(std::shared_ptr<IRectangleRenderer> renderer);
	void render(SDL_Renderer* gameRenderer); 
};
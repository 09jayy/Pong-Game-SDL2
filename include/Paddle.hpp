#pragma once
#include <iostream>
#include <memory>
#include "SDL.h"
#include "Entity.hpp"
#include "IRectangleRenderer.hpp"
#include "IMoveableY.hpp"

class Paddle : public Entity
{
private:
	int width, height;
	std::shared_ptr<IRectangleRenderer> renderer;
	SDL_Color color; 

	std::unique_ptr<IMoveableY> controller;
public:	
	Paddle() = default;
	Paddle(int x, int y, int width, int height);

	void setController(std::unique_ptr<IMoveableY> newController);
	void addVelocity(float add); 
	void move(); 

	void setRenderer(std::shared_ptr<IRectangleRenderer> renderer);
	void render(SDL_Renderer* gameRenderer); 
};
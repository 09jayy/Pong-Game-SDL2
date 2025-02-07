#pragma once
#include <iostream>
#include <memory>
#include "Entity.hpp"
#include "Circle.hpp"

class Ball : public Entity , public Circle
{
private:
	SDL_Color color; 
	float xVel, yVel; 

public:
	Ball(); 
	Ball(int x, int y, int radius); 

	void render(SDL_Renderer* gameRenderer);
	void move(); 
};
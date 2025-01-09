#pragma once
#include <iostream>
#include <memory>
#include "SDL.h"
#include "Entity.hpp"
#include "IMoveableY.hpp"

class Paddle : public Entity
{
private:
	int width, height; 
	SDL_Color color; 

public:	
	Paddle() = default;
	Paddle(int x, int y, int width, int height);
 
	void move();  
	
	void render(SDL_Renderer* gameRenderer); 
};
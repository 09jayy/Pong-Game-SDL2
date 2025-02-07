#pragma once
#include <iostream>
#include <memory>
#include "SDL.h"
#include "Entity.hpp"
#include "Rect.hpp"

class Paddle : public Rect
{
private:
	SDL_Scancode upKey;
	SDL_Scancode downKey;
	SDL_Color color; 

public:	
	Paddle() = default; 
	Paddle(int xPos, int yPos, int width, int height, SDL_Scancode upKey, SDL_Scancode downKey);
 
	void processInput(const Uint8* keyboardState);
	
	void render(SDL_Renderer* gameRenderer); 
};
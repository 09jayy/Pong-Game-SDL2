#pragma once
#include <iostream>
#include <memory>
#include "Entity.hpp"

class Ball : public Entity
{
private:
	int32_t radius; 
	SDL_Color color; 

public:
	Ball(); 
	Ball(int x, int y, int radius); 

	void render(SDL_Renderer* gameRenderer);
};
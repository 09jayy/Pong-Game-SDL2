#pragma once
#include "SDL.h"

/* Base call for all entities that will be rendered to the screen */
class Entity
{
public: 
	float xPos, yPos; 
public:
	Entity() : xPos(0.0f), yPos(0.0f) {};
	Entity(int x, int y) : xPos(x), yPos(y) {};
	virtual void render(SDL_Renderer* renderer) = 0; 
};
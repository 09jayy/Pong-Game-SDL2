#pragma once
#include "SDL.h"

/* Base call for all entities that will be rendered to the screen */
class Entity
{
protected: 
	float xPos, yPos; 
public:
	Entity() = default;
	Entity(int x, int y) : xPos(x), yPos(y) {};
	virtual void render(SDL_Renderer* renderer) = 0; 
};
#pragma once
#include "Entity.hpp"
#include "CollisionManager.hpp"

/* Base class intended for classes requiring width and height properties */
class Rect : public Entity
{
protected:
	int width, height; 
public:
	Rect() = default; 
	Rect(float xPos, float yPos, int width, int height) : Entity(xPos, yPos) , width(width), height(height) {};
	
	friend class CollisionManager;
};
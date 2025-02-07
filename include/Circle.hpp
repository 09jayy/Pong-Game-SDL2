#pragma once
#include <iostream>
#include "Entity.hpp"
#include "CollisionManager.hpp"

/* Base class for classes requiring circle properties: radius */
class Circle : public Entity
{
protected:
	int32_t radius;
public:
	Circle(float xPos, float yPos, int radius) : Entity(xPos,yPos), radius(radius) {};
	
	friend class CollisionManager; 
};
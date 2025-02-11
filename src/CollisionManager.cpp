#include <cmath>
#include "CollisionManager.hpp"
#include "Game.hpp"

int CollisionManager::checkCollision(Circle* circle, Rect* rect)
{
	// 1. Find the closest edge the circle is to the rect to be used for testing
	float testX = circle->radius; 
	float testY = circle->yPos; 
	if (circle->xPos < rect->xPos) // left edge
	{
		testX = rect->xPos;
	}
	else if (circle->xPos > rect->xPos + rect->width) // right edge
	{
		testX = rect->xPos + rect->width; 
	}; 

	if (circle->yPos < rect->yPos) // top edge 
	{
		testY = rect->yPos;
	}
	else if (circle->yPos > rect->yPos + rect->height) // bottom edge 
	{
		testY = rect->yPos + rect->height;
	}; 

	// 2. Use Pythagoras Theorem to find distance between center circle and two edges
	float distX = circle->xPos - testX; 
	float distY = circle->yPos - testY;
	float distance = std::sqrt((distX * distX) + (distY * distY)); 

	// 3. Compare distance to circle radius, return distance from top edge
	return (distance <= circle->radius) ? circle->yPos - rect->yPos: -1;  
};

Border CollisionManager::checkBorderCollision(Circle* circle)
{
	if (circle->xPos - circle->radius <= 0) // left border collision
	{
		return LEFT; 
	}
	else if (circle->xPos + circle->radius >= Game::GET_WIDTH()) // right border collision
	{ 
		return RIGHT; 
	}
	else if (circle->yPos - circle->radius <= 0) // top border collision
	{
		return TOP; 
	}
	else if (circle->yPos + circle->radius >= Game::GET_HEIGHT()) // bottom border collision
	{
		return BOTTOM; 
	}
	return NONE; 
}
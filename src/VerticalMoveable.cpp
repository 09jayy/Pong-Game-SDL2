#include "VerticalMoveable.hpp"

void VerticalMoveable::adjustVelocity(float add)
{
	const float MAX_X = 3.0;
	xVar = (xVar + add >= MAX_X) ? MAX_X : xVar + add; 
	xVar = (xVar + add <= MAX_X * -1) ? MAX_X * -1 : xVar + add; 

	yVelocity = 2 * (xVar * xVar);
};

void VerticalMoveable::move(int& y)
{
	y += yVelocity; 
}; 
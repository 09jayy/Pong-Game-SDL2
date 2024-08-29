#include <iostream>
#include "VerticalMoveable.hpp"

void VerticalMoveable::adjustVelocity(float add)
{
	const float MIN_MAX_X = 2.0; 
	if (add > 0)
	{
		xVar += add; 
		xVar = std::min(xVar, MIN_MAX_X);
	}
	else
	{
		xVar += add;
		xVar = std::min(xVar, MIN_MAX_X*-1);
	}
	float xVarAbs = std::abs(xVar);
	yVelocity = 2*pow(xVarAbs,3) * ((xVar < 0) ? -1 : 1);
};

void VerticalMoveable::killVelocity()
{
	yVelocity = 0; 
	xVar = 0; 
}

void VerticalMoveable::move(int& y)
{
	y += yVelocity; 
}; 
#include <iostream>
#include "VerticalMoveable.hpp"

void VerticalMoveable::adjustVelocity(float add)
{
	if (add > 0 && xVar < 0)
	{
		xVar = 0;
	}
	else if (add < 0 && xVar > 0)
	{
		xVar = 0; 
	}

	const float MAX_X = 2.0;
	xVar = (xVar + add >= MAX_X) ? MAX_X : xVar + add; 
	xVar = (xVar + add <= MAX_X * -1) ? MAX_X * -1 : xVar + add; 

	yVelocity = 2 * (xVar * xVar * xVar);

	std::cout << "yVelocity: " << yVelocity << std::endl; 
	std::cout << "xVar: " << xVar << std::endl; 
};

void VerticalMoveable::move(int& y)
{
	y += yVelocity; 
}; 
#pragma once
#include <iostream>

/* Base class for classes requiring circle properties: radius */
class Circle
{
protected:
	int32_t radius;
public:
	Circle() = default; 
	Circle(int radius) : radius(radius) {}; 
};
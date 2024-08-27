#pragma once
#include "IMoveableY.hpp"

class VerticalMoveable : public IMoveableY
{
private:
	float yVelocity;
	float xVar;
public:
	VerticalMoveable() = default;
	~VerticalMoveable() = default; 

	void adjustVelocity(float add);
	void move(int& y); 
};
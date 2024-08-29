#pragma once

/*
Interface encapsulates movement functionality for entities that move based on user input across Y axis
*/
class IMoveableY
{
public:
	virtual void killVelocity() = 0; 
	virtual void adjustVelocity(float add) = 0;
	virtual void move(int& y) = 0;
	virtual ~IMoveableY() {};
};
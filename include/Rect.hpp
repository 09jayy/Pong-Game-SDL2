#pragma once

class Rect
{
protected:
	int width, height; 
public:
	Rect() = default;
	Rect(int width, int height) : width(width), height(height) {};
};
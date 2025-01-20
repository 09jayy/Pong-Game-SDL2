#pragma once

/* Base class intended for classes requiring width and height properties */
class Rect
{
protected:
	int width, height; 
public:
	Rect() = default;
	Rect(int width, int height) : width(width), height(height) {};
};
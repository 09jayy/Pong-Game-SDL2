#pragma once
#include <iostream>
#include <concepts>
#include "Entity.hpp"
#include "Rect.hpp"
#include "Circle.hpp"

class Rect; 
class Circle; 

enum Border
{
	NONE,
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
};

class CollisionManager
{
public:
	static int checkCollision(Circle* circle, Rect* rect); 
	static Border checkBorderCollision(Circle* circle); 
};
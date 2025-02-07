#pragma once
#include <iostream>
#include <concepts>
#include "Entity.hpp"
#include "Rect.hpp"
#include "Circle.hpp"

class Rect; 
class Circle; 

class CollisionManager
{
public:
	static int checkCollision(Circle* circle, Rect* rect); 
	static int checkBorderCollision(Circle* circle); 
};
#pragma once

/* Base call for all entities that will be rendered to the screen */
class Entity
{
protected: 
	int x, y; 
public:
	Entity() = default;
	Entity(int x, int y) : x(x), y(y) {};
};
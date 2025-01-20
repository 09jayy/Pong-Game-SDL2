#pragma once
#include <iostream>
#include <concepts>
#include "Entity.hpp"
#include "Rect.hpp"
#include "Circle.hpp"

template <typename T>
concept RectEntity = std::is_base_of<Entity, T>::value && std::is_base_of<Rect, T>::value; 

template <typename T>
concept CircleEntity = std::is_base_of<Entity, T>::value && std::is_base_of<Circle, T>::value; 

class CollisionManager
{
public:
	int checkCollision(const CircleEntity auto& circle, const RectEntity auto& rect); 
	int checkBorderCollision(const CircleEntity auto& circle); 
};
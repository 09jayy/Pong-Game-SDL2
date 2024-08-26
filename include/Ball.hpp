#pragma once
#include <iostream>
#include <memory>
#include "Entity.hpp"
#include "ICircleRenderer.hpp"

class Ball : public Entity
{
private:
	int32_t radius; 
	std::unique_ptr<ICircleRenderer> renderer; 
	SDL_Color color; 

public:
	Ball(); 
	Ball(int x, int y, int radius); 

	void setRenderer(std::unique_ptr<ICircleRenderer> renderer);
	void render(SDL_Renderer* gameRenderer);
};
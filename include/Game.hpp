#pragma once
#include <iostream>
#include <memory>
#include "SDL.h"
#include "Paddle.hpp" 
#include "Ball.hpp"

class Game 
{
private:
	bool running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	const SDL_Color backgroundColor;

	Paddle paddle1;
	Paddle paddle2;
	std::shared_ptr<IRectangleRenderer> sharedPaddleRenderer; 
	Ball ball;
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning() { return running; };

	SDL_Renderer* getRenderer() { return renderer; };
	const SDL_Color& getBackgroundColor() const { return backgroundColor; };
};
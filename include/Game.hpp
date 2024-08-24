#pragma once
#include <iostream>
#include <memory>
#include "SDL.h"
#include "Paddle.hpp" 

class Game 
{
private:
	bool running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	const SDL_Color backgroundColor;
	Paddle paddle1;
	std::shared_ptr<IRectangleRenderer> sharedPaddleRenderer; 

public:
	Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Game();

	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning() { return running; };

	SDL_Renderer* getRenderer() { return renderer; };
	const SDL_Color& getBackgroundColor() const { return backgroundColor; };
};
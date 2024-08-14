#pragma once
#include "SDL.h"

class Game 
{
private:
	bool running;
	SDL_Window* window;
	static SDL_Renderer* renderer;
	bool hasFailed;

public:
	Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	~Game();

	void handleEvents();
	void update();
	void render();
	void clean();
	void fail();

	bool isRunning() { return running; };

	static SDL_Renderer* getRenderer() { return renderer; };
};
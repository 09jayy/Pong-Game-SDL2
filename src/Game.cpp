#include <iostream>
#include "SDL.h"
#include "Game.hpp" 

SDL_Renderer* Game::renderer = nullptr; 

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	running = true;
	window = nullptr;
	hasFailed = false;
	renderer = nullptr; 

	int flags = 0;

	if (fullscreen) 
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		std::cout << "GAME INITIALISED" << "\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
		{
			std::cout << "Window Created" << "\n";
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer) 
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer created" << "\n";
		}

		running = true;
	}
	else 
	{
		running = false;
	}
} 

Game::~Game()
{

}

void Game::handleEvents()
{

}

void Game::update()
{
	SDL_Event event; 
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			running = false;
			break; 
	}
}

void Game::render()
{
	// Clear renderer buffer
	SDL_RenderClear(renderer);

	// Render components

	// Present renderer buffer
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

void Game::fail()
{
	hasFailed = true; 
}
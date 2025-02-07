#include <iostream>
#include<memory>
#include "SDL.h"
#include "Game.hpp" 
#include "Ball.hpp"

int Game::GAME_WIDTH = 1280; 
int Game::GAME_HEIGHT = 720; 

Game::Game() : backgroundColor({ 0,0,0,255 }), running(false), window(nullptr), renderer(nullptr) {}; 

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// Initialise SDL Elements
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cout << "SDL failed to initialise" << std::endl;
		return; 
	}

	window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	if (!window)
	{
		std::cout << "Window failed to create" << std::endl; 
		return; 
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer)
	{
		std::cout << "Renderer failed to create" << std::endl;
		return; 
	}

	/* Initialise entities */ 
	
	// Initialise Paddles
	paddle1 = Paddle(150, 0, 20, 80, SDL_SCANCODE_W, SDL_SCANCODE_S);
	paddle2 = Paddle(GAME_WIDTH-20-150, 720-80, 20, 80, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN);

	// Initialise ball
	ball = Ball(640, 360, 10);

	running = true;
};

Game::~Game()
{

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			running = false;
			break;
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);

	paddle1.processInput(state);
	paddle2.processInput(state); 
}

void Game::update()
{
	ball.move(); 
}

void Game::render()
{
	// Set draw color to render background first
	SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);

	// Clear renderer buffer
	SDL_RenderClear(renderer);

	// Render components
	paddle1.render(renderer);
	paddle2.render(renderer); 
	ball.render(renderer);

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
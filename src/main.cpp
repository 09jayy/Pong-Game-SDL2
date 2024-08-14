// main.cpp : Defines the entry point for the application

#include <iostream>
#include "SDL.h"
#include "Game.hpp"

int main(int argc, char* argv[])
{
    
    const int FPS = 30;

    Uint32 elapsed = 0;
    int frameTime = 0;

    Game game("Pong Game by Jay", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);

    while (game.isRunning()) 
    {
        elapsed = SDL_GetTicks();

        game.handleEvents();
        game.update();
        game.render();

        frameTime = SDL_GetTicks() - elapsed;
        if (1000 / FPS > frameTime) 
        {
            SDL_Delay((1000 / FPS) - frameTime);
        };
    }
    game.clean();

	return 0;
}

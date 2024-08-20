// main.cpp : Defines the entry point for the application

#include <iostream>
#include "SDL.h"
#include "Game.hpp"

int main(int argc, char* argv[])
{
    const int GAME_WIDTH = 1280;
    const int GAME_HEIGHT = 720;
    const int FPS = 30;

    Uint32 elapsed = 0;
    int frameTime = 0;

    Game game("Pong Game by Jay", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, GAME_WIDTH, GAME_HEIGHT, false);

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

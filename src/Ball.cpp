#include "Ball.hpp"
#include "SDL.h"
#include "CollisionManager.hpp"; 

Ball::Ball() : Circle(0.0f, 0.0f, 0), color({ 255,255,255,255 }), xVel(0.0f), yVel(0.0f) {}; 
Ball::Ball(int xPos, int yPos, int radius) : Circle(xPos,yPos,radius), color({ 255,255,255,255 }), xVel(10.0f), yVel(0.0f) {};

void Ball::render(SDL_Renderer* gameRenderer)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        // Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(gameRenderer, xPos + x, yPos - y);
        SDL_RenderDrawPoint(gameRenderer, xPos + x, yPos + y);
        SDL_RenderDrawPoint(gameRenderer, xPos - x, yPos - y);
        SDL_RenderDrawPoint(gameRenderer, xPos - x, yPos + y);
        SDL_RenderDrawPoint(gameRenderer, xPos + y, yPos - x);
        SDL_RenderDrawPoint(gameRenderer, xPos + y, yPos + x);
        SDL_RenderDrawPoint(gameRenderer, xPos - y, yPos - x);
        SDL_RenderDrawPoint(gameRenderer, xPos - y, yPos + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}; 

void Ball::checkPaddleCollision(Paddle& paddle)
{
    int a = CollisionManager::checkCollision(this, &paddle); 
}; 

void Ball::move()
{
    std::cout << xPos << ',' << yPos << std::endl; 
    std::cout << "vel: " << xVel << ',' << yVel << std::endl; 
    xPos = xPos + xVel;
    yPos = yPos + yVel; 
}; 
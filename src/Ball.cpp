#include <iostream>
#include <cmath>
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

/*
* Calculates new x and y velocities upon collision with rect object
* 
* @param rect: object to check collision with
*/
void Ball::checkRectCollision(Rect& rect)
{
    float collide = CollisionManager::checkCollision(this, &rect); 
    if (collide != -1)
    {
        xVel = xVel * -1; 
        yVel = yVel * -1 + (10*-0.00064f * pow(collide-40,2) + 1); 
    };
}; 

void Ball::checkBorderCollision()
{
    bool collide = CollisionManager::checkBorderCollision(this); 
    if (collide != NONE)
    {
        // Check for collision with left and right borders
        if (collide == LEFT || collide == RIGHT)
        {
            xVel *= -0.95f;  // Reverse and apply damping factor for smoother bounce
            yVel += (rand() % 3 - 1) * 0.5f;  // Add slight random variation in vertical velocity
        }

        // Check for collision with top and bottom borders
        if (collide == BOTTOM || collide == TOP)
        {
            yVel *= -1.05f;  // Reverse and amplify for a higher bounce effect
            xVel += (rand() % 3 - 1) * 0.3f;  // Add slight random variation in horizontal velocity
        }
    }; 
}; 

void Ball::move()
{
    std::cout << xPos << ',' << yPos << std::endl; 
    std::cout << "vel: " << xVel << ',' << yVel << std::endl; 
    xPos = xPos + xVel;
    yPos = yPos + yVel; 
}; 
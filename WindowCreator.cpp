#include <iostream>
#include <SDL2/SDL.h>


#include "WindowCreator.hpp"

//window constructor
CreateWindow::CreateWindow(const char* titlu_, int height_, int width_)
{
    window = SDL_CreateWindow(titlu_, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_SHOWN); //creare fereastra jocului
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    presentRenderer=renderer;
}

//window destructor
void CreateWindow::destructor()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//clearing the renderer
void CreateWindow::clear()
{
    SDL_RenderClear(renderer);
}

//presenting the current frame
void CreateWindow::present()
{
    SDL_RenderPresent(renderer);
}

//choosing the color for the renderer
void CreateWindow::drawColor(int r_, int g_, int b_, int a_)
{
    SDL_SetRenderDrawColor(renderer, r_, g_, b_, a_);
}
//the actual score is presented as the title of the window
void CreateWindow::setScore(int s)
{
    snprintf(scoreText, 20, "Score: %d", s);
    SDL_SetWindowTitle(window, scoreText);
}

//'You win!' message when winning
void CreateWindow::endGame()
{
    snprintf(scoreText, 20, "You win!");
    SDL_SetWindowTitle(window, scoreText);
}

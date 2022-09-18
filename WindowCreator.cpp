//
//  WindowCreator.cpp
//  Proiect
//
//  Created by Lysander Pitu on 24.03.2022.
//

#include <iostream>
#include <SDL2/SDL.h>


#include "WindowCreator.hpp"

//constructorul ferestrei
CreareFereastra::CreareFereastra(const char* titlu_, int height_, int width_)
{
    window = SDL_CreateWindow(titlu_, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width_, height_, SDL_WINDOW_SHOWN); //creare fereastra jocului
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    presentRenderer=renderer;
}

//destructorul ferestrei
void CreareFereastra::destructor()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//eliberarea render-ului din buffer pentru a face loc unui render nou pentru un frame nou
void CreareFereastra::clear()
{
    SDL_RenderClear(renderer);
}

//presentarea render-ului(frame-ului) actual
void CreareFereastra::present()
{
    SDL_RenderPresent(renderer);
}

//alegerea culorii pe care o deseneaza renderer-ul
void CreareFereastra::drawColor(int r_, int g_, int b_, int a_)
{
    SDL_SetRenderDrawColor(renderer, r_, g_, b_, a_);
}
//setez titlul window-ului ca si scorul actual
void CreareFereastra::setScore(int s)
{
    //functie de convertire din numar in text a librariei <iostream>
    snprintf(scoreText, 20, "Score: %d", s);
    SDL_SetWindowTitle(window, scoreText);
}

//afisarea textului "You win!" cand s-a ajuns la conditia de castig
void CreareFereastra::endGame()
{
    snprintf(scoreText, 20, "You win!");
    SDL_SetWindowTitle(window, scoreText);
}

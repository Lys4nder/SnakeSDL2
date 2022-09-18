
#pragma once
#ifndef WindowCreator_hpp
#define WindowCreator_hpp

#include <SDL2/SDL.h>
#include <iostream>


#endif /* WindowCreator_hpp */

class CreateWindow
{
private:
    SDL_Window* window; //game window
    SDL_Renderer* renderer; //renderer
    char scoreText[20];
public:
    CreateWindow(const char*, int, int);
    void clear();
    void present();
    void drawColor(int, int, int, int);
    void destructor();
    void setScore(int);
    void endGame();
    SDL_Renderer* presentRenderer;
    
};

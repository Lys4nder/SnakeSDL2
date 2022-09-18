//
//  WindowCreator.hpp
//  Proiect
//
//  Created by Lysander Pitu on 24.03.2022.
//
#pragma once
#ifndef WindowCreator_hpp
#define WindowCreator_hpp

#include <SDL2/SDL.h>
#include <iostream>


#endif /* WindowCreator_hpp */

class CreareFereastra
{
private:
    SDL_Window* window; //fereastra jocului
    SDL_Renderer* renderer; //motorul de randare
    char scoreText[20];
public:
    CreareFereastra(const char*, int, int);
    void clear();
    void present();
    void drawColor(int, int, int, int);
    void destructor();
    void setScore(int);
    void endGame();
    SDL_Renderer* presentRenderer;
    
};

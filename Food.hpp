//
//  Food.hpp
//  Proiect
//
//  Created by Lysander Pitu on 25.03.2022.
//
#pragma once
#ifndef Food_hpp
#define Food_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include "WindowCreator.hpp"

#endif /* Food_hpp */

class Food
{
    SDL_Rect instance;
    int x,y,h,w;
public:
    Food(int x, int y, int h, int w);
    int getX();
    int getY();
    void display(SDL_Renderer*);
    void updatePos(SDL_Renderer*);
};

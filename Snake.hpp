#pragma once
#ifndef Snake_hpp
#define Snake_hpp

#include <iostream>
#include <deque>
#include <SDL2/SDL.h>
#include "WindowCreator.hpp"

#define height 600
#define width 600

#endif /* Snake_hpp */



class Snake
{
    SDL_Rect head;
    int x,y,h,w;
    enum Direction {DOWN, LEFT, RIGHT, UP};
    int dir = 0;
    std::deque<SDL_Rect> rq;
    int size = 1;
public:
    Snake(int x, int y, int h, int w);
    int getX();
    int getY();
    void display(SDL_Renderer*);
    void updateDir(int dir);
    void resetPos();
    bool selfColission();
    void snakeBody();
    void getSize();
    void updateSize();
    void resetSize();
    bool appleIsOnSnake(int, int);
};

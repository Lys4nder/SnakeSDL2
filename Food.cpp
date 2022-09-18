#include "Food.hpp"


//this constructor copies the x and y coordinates, h and w are the height and width of the texture
//the instance variable is a variable that belongs to the SDL_Rect class
Food::Food(int x, int y, int h, int w)
{
    instance.x=x;
    instance.y=y;
    instance.h=h;
    instance.w=w;
}

//sets the color of the apple using RGBA, i chose purple :D
void Food::display(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 123, 56, 201, 1);
    SDL_RenderFillRect(renderer, &instance);
}

//updating the position of the newly generated apple
void Food::updatePos(SDL_Renderer* renderer)
{
    instance.x=rand()%60*10;
    instance.y=rand()%60*10;
    display(renderer);
}

//returning the X and Y coordinates for the game logic
int Food::getX()
{
    return instance.x;
}

int Food::getY()
{
    return instance.y;
}

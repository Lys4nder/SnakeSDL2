//
//  Food.cpp
//  Proiect
//
//  Created by Lysander Pitu on 25.03.2022.
//

#include "Food.hpp"

//constructorul care copiaza coordonatele x si y, inaltimea texturii - h si latimea texturii - w
//variabila instance este o clasa de tipul SDL_Rect, adica un "rectangle" care are
//coordonatele x,y, inaltimea h (height) si latimea w (width)
Food::Food(int x, int y, int h, int w)
{
    instance.x=x;
    instance.y=y;
    instance.h=h;
    instance.w=w;
}

//setarea culorii marului si randarea lui
void Food::display(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 123, 56, 201, 1);
    SDL_RenderFillRect(renderer, &instance);
}

//updatarea pozitiei noului mar
void Food::updatePos(SDL_Renderer* renderer)
{
    instance.x=rand()%60*10;
    instance.y=rand()%60*10;
    display(renderer);
}

//returnarea coordonatelor X si Y pentru logica jocului;
int Food::getX()
{
    return instance.x;
}

int Food::getY()
{
    return instance.y;
}

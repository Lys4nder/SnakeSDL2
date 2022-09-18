//
//  Snake.cpp
//  Proiect
//
//  Created by Lysander Pitu on 27.03.2022.
//

#include "Snake.hpp"

//constructorul de copiere
//variabila head este o clasa de tipul SDL_Rect, adica un "rectangle" care are
//coordonatele x,y, inaltimea h (height) si latimea w (width)
Snake::Snake(int x, int y, int h, int w)
{
    head.x=x;
    head.y=y;
    head.h=h;
    head.w=w;
}

//afisarea corpului sarpelui, care "urmareste" capul
void Snake::display(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    std::for_each(rq.begin(), rq.end(), [&](auto& snake_segment)
    {
        SDL_RenderFillRect(renderer, &snake_segment);
    });
}

//updatarea directiei de deplasare a capului
void Snake::updateDir(int dir)
{
    switch (dir)
    { //schimbarea directiei
        case DOWN:
            head.y +=10;
            break;
        case UP:
            head.y -=10;
            break;
        case LEFT:
            head.x -=10;
            break;
        case RIGHT:
            head.x +=10;
            break;
        default:
            break;
    }
}

/*
generarea corpului sarpelui dupa ce a mancat un mar cu ajutorul
librariei <deque> (double-ended-queue)
am ales sa folosesc aceasta librariei deoarece astfel pot aloca dinamic si manipula
mai usor sarpele, care de fapt este un simplu vector.
functiile librariei permit insertii si eliminari mult mai eficiente decat daca as fi
folosit un simplu vector
mai multe aici:
 https://en.cppreference.com/w/cpp/container/deque
*/
void Snake::snakeBody()
{
    rq.push_front(head);
    while (rq.size() > size)
        rq.pop_back();
}

//updatarea pozitiei
void Snake::resetPos()
{
    head.x=height/2;
    head.y=width/2;
}

//verificare daca capul sarpelui s-a lovit de corpul acestuia
bool Snake::selfColission()
{
    bool hit=false;
    //parcurgerea corpului sarpelui
    std::for_each(rq.begin(), rq.end(), [&](auto &snake_segment)
    {
        if (head.x==snake_segment.x && head.y == snake_segment.y)
        {
            hit = true;
        
        }
    });
    return hit;
}

//verificare daca coordonatele marului generat (x_, y_) se afla pe corpul sarpelui
bool Snake::appleIsOnSnake(int x_, int y_)
{
    bool isOnSnake = true;
    std::for_each(rq.begin(), rq.end(), [&](auto &snake_segment) //Verificare daca merele s-au generat pe corpul sarpelui
        {
        if (x_ != snake_segment.x && y_ != snake_segment.y)
            isOnSnake = false;
    });
    return isOnSnake;
}

//updatarea marimii sarpelui dupa ce a mancat un mar
void Snake::updateSize()
{
    size+=6;
}

//resetarea pozitiei
void Snake::resetSize()
{
    size=1;
}

//returnarea coordonatelor pentru logica jocului
int Snake::getY()
{
    return head.y;
}

int Snake::getX()
{
    return head.x;
}

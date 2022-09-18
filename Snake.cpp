#include "Snake.hpp"

//snake constructor
Snake::Snake(int x, int y, int h, int w)
{
    head.x=x;
    head.y=y;
    head.h=h;
    head.w=w;
}

//rendering the body of the snake which 'follows' the snake's head
void Snake::display(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    std::for_each(rq.begin(), rq.end(), [&](auto& snake_segment)
    {
        SDL_RenderFillRect(renderer, &snake_segment);
    });
}

//updating the direction of the snakes's head
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
using <deque> lib in order to create the movement
 https://en.cppreference.com/w/cpp/container/deque
*/
void Snake::snakeBody()
{
    rq.push_front(head);
    while (rq.size() > size)
        rq.pop_back();
}

//updating pos
void Snake::resetPos()
{
    head.x=height/2;
    head.y=width/2;
}

//checking if the head of the snake collided with its body
bool Snake::selfColission()
{
    bool hit=false;
    
    std::for_each(rq.begin(), rq.end(), [&](auto &snake_segment)
    {
        if (head.x==snake_segment.x && head.y == snake_segment.y)
        {
            hit = true;
        
        }
    });
    return hit;
}

//checking if the newly generated apple is on the snake's body
bool Snake::appleIsOnSnake(int x_, int y_)
{
    bool isOnSnake = true;
    std::for_each(rq.begin(), rq.end(), [&](auto &snake_segment)
        {
        if (x_ != snake_segment.x && y_ != snake_segment.y)
            isOnSnake = false;
    });
    return isOnSnake;
}

//updating the size after eating an apple
void Snake::updateSize()
{
    size+=6;
}

//size reset
void Snake::resetSize()
{
    size=1;
}

//returning X and Y coordinates for the game logic
int Snake::getY()
{
    return head.y;
}

int Snake::getX()
{
    return head.x;
}

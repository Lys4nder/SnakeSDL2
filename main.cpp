//
//  main.cpp
//  Project
//
//  Created by Lys4nder on 24.03.2022.
//

#include <iostream>
#include <SDL2/SDL.h> //for windows use <SDL.h>

//size of the window
#define height 600
#define width 600

#include "WindowCreator.hpp"
#include "Food.hpp"
#include "Snake.hpp"


int main(int argc, const char * argv[])
{
    //creating with costructors the window, snake's head and the food
    CreateWindow window("Snake - Lysander Pitu", height, width);
    Snake head{height /2, width /2, 10, 10}; //the head generates in the middle of the window, being a 10x10 pixel rectangle
    Food testApple(rand()% 60*10, rand()% 60*10,10,10);
    
    //local variables for the game logic
    int score = 0, maxScore=6000;
    bool appleEaten = false;
    bool gameRunning = true;
    
    //the 2 variables below are necessary for the movement
    int dir=0;
    enum Direction {DOWN, LEFT, RIGHT, UP};

    //the variable below handles user input
    SDL_Event event;
    
    
    while (gameRunning) //game running loop
    {
        while (SDL_PollEvent(&event)) 
        {   
            if (event.type == SDL_QUIT)
                gameRunning = false;
            if (event.type == SDL_KEYDOWN)
            {   //user input handler for movement
                if (event.key.keysym.sym == SDLK_DOWN)
                    dir = DOWN;
                if (event.key.keysym.sym == SDLK_LEFT)
                    dir = LEFT;
                if (event.key.keysym.sym == SDLK_RIGHT)
                    dir = RIGHT;
                if (event.key.keysym.sym == SDLK_UP)
                    dir = UP;
            }
        }
        
        //updating movement dir
        head.updateDir(dir);
        
        //checking if the head collided with and apple
        if (head.getX()==testApple.getX()  && head.getY()==testApple.getY())
        {
            score+=10;
            window.setScore(score);
            appleEaten = true;
            head.updateSize(); //growing the snake's size
            testApple.updatePos(window.presentRenderer); //generating a new apple
        }
        
        //checking if the new apple is on the snake
        if (appleEaten)
        {
            bool appleIsOnSnake = head.appleIsOnSnake(testApple.getX(), testApple.getY());
            while (appleIsOnSnake)
            {
                testApple.updatePos(window.presentRenderer);
                appleIsOnSnake = head.appleIsOnSnake(testApple.getX(), testApple.getY());
            }
            appleEaten = false;
        }
        
        //self colision, resetting the score, size and position
        if (head.selfColission())
        {
            head.resetPos();
            head.resetSize();
            score=0;
            window.setScore(score);
            testApple.updatePos(window.presentRenderer);
        }
        
        //generating the body
        head.snakeBody();
        
        //checking if the snakes leaves the window, then we reset the score, size and position
        if ((head.getY() > height || head.getY() < 0) || (head.getX() > width || head.getX() < 0))
        {
            score=0;
            window.setScore(score);
            head.resetPos();
            head.resetSize();
            testApple.updatePos(window.presentRenderer);
            
        }
        //winning condition
        if (score==maxScore)
            gameRunning=false;
        
        //coloring the map - black
        window.drawColor(0, 0, 0, 255);
        window.clear();
        
        //displaying the snake and the food
        head.display(window.presentRenderer);
        testApple.display(window.presentRenderer);
        
        //rendering the frames
        window.present();
        SDL_PumpEvents();
        
        //delay between frames, so the game is not too fast
        //change the number to adjust speed, the higher the number, the slower the game gets (miliseconds)
        SDL_Delay(45);
        

    }
    
    if (score==maxScore)
    {
        window.clear();
        window.endGame();
        SDL_PumpEvents();
        SDL_Delay(5000);
    }
    
    
    window.destructor();
}

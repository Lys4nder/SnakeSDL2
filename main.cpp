//
//  main.cpp
//  Proiect
//
//  Created by Lys4nder Pitu on 24.03.2022.
//

#include <iostream>
#include <SDL2/SDL.h> //pentru windowsOS trebuie inclus <SDL.h>

//marimea plansei de joc
#define height 600
#define width 600

#include "WindowCreator.hpp"
#include "Food.hpp"
#include "Snake.hpp"


int main(int argc, const char * argv[])
{
    //crearea prin constructori a ferestrei, sarpelui si marului
    CreareFereastra window("Snake - Lysander Pitu", height, width);
    Snake head{height /2, width /2, 10, 10}; //capul sarpelui se genereaza la mijlocul plansei de joc si are dimensiunea texturii de 10x10 pixeli
    Food testApple(rand()% 60*10, rand()% 60*10,10,10); //marul se genereaza la o pozitie aleatoare, dimensiunea la fel cu cea a sarpelui
    
    //declararea de variabile locale necesare pentru logica jocului
    int score = 0, maxScore=6000;
    bool appleEaten = false;
    bool gameRunning = true;
    //cele 3 declarari de mai jos sunt necesare  pentru evenimentele din joc:
    //primele 2 sunt pentru directia de deplasare a sarpelui
    int dir=0;
    enum Direction {DOWN, LEFT, RIGHT, UP};
    //aceasta variabila definita de clasa SDL_Event apartine librariei grafice si gestioneaza
    //evenimente, adica apasarea butoanelor de control de pe tastatura (sus/jos/stanga/dreapta)
    //si daca se apasa butonul de inchidere a ferestrei
    SDL_Event event;
    
    
    while (gameRunning) //loop-ul principal al jocului
    {
        while (SDL_PollEvent(&event)) //loop-ul de apasare de butoane
        {   //apasarea butonului de inchidere a ferestrei
            if (event.type == SDL_QUIT)
                gameRunning = false;
            if (event.type == SDL_KEYDOWN)
            {   //apsarea butoanelor de directie
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
        
        //updatarea directiei sarpelui
        head.updateDir(dir);
        
        //verificarea coliziunii cu un mar si updatarea scorului ca titlu
        if (head.getX()==testApple.getX()  && head.getY()==testApple.getY())
        {
            score+=10;
            window.setScore(score);
            appleEaten = true;
            head.updateSize(); //cresterea dimensiunii sarpelui
            testApple.updatePos(window.presentRenderer); //generarea unui nou mar
        }
        
        //verific daca noul mar generat s-a generat pe corpul sarpelui, si daca da, generez un nou mar
        //pana cand nu se mai afla pe corpul sarpelui
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
        
        //Coliziunea cu sine, daca sarpele se loveste de corpul sau, marimea se reseteaza,
        //pozitia sarpelui se reseteaza la mijloc, se genereaza un nou mar si resetez scorul
        if (head.selfColission())
        {
            head.resetPos();
            head.resetSize();
            score=0;
            window.setScore(score);
            testApple.updatePos(window.presentRenderer);
        }
        
        //Generarea corpului sarpelui astfel incat sa urmareasca capul
        head.snakeBody();
        
        //Daca sarpele iese din harta, capul se reseteaza la mijloc, i se reseteaza marimea, se genereaza un nou mar si resetez sccorul
        if ((head.getY() > height || head.getY() < 0) || (head.getX() > width || head.getX() < 0))
        {
            score=0;
            window.setScore(score);
            head.resetPos();
            head.resetSize();
            testApple.updatePos(window.presentRenderer);
            
        }
        //conditia de castig
        if (score==maxScore)
            gameRunning=false;
        
        //Culoarea plansei de joc - negru
        window.drawColor(0, 0, 0, 255);
        window.clear();
        
        //Culoarea sarpelui si marului
        head.display(window.presentRenderer);
        testApple.display(window.presentRenderer);
        //Randarea frame-urilor
        window.present();
        SDL_PumpEvents();
        //un delay de 45ms intre fiecare randare de frame-uri, ca jocul sa nu fie prea rapid
        //adica sarpele sa se miste prea rapid
        SDL_Delay(85);
        

    }
    //afisarea textului "You win!" cand s-a ajuns la conditia de castig
    if (score==maxScore)
    {
        window.clear();
        window.endGame();
        SDL_PumpEvents();
        SDL_Delay(5000);
    }
    //distrugerea ferestrei si inchiderea librariei SDL
    window.destructor();
}


/*
 Surse de inspiratie:
 https://lazyfoo.net/tutorials/SDL/index.php
 https://www.youtube.com/watch?v=HYChxi7rcr0&list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS&index=7
 https://en.cppreference.com/w/cpp/container/deque
 */

// Adventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main()
{
    Game game;
    game.InitGame();
    while (game.GetPlaying())
    {
        game.mainMenu();
    }
    return 0;

}


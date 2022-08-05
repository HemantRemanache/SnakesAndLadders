#pragma once
// SnakesAndLadders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<conio.h>
#include<vector>
#include <chrono>
#include"Players.h"
#include"Dice.h"
#include"Board.h"
class SnakesAndLadders {
    std::vector<Players>players;
    Dice *dice;
    Board *board;
    int playerCount;
    Players GetNextPlayer(Players p1);
public:
    SnakesAndLadders(int playercount);
    void GetDetails();
    void Play();
    ~SnakesAndLadders() {
        delete dice;
        delete board;
      /*  for (auto i = players.begin(); i != players.end(); i++)
        {
            delete *i;
        }*/
    }

};

int main()
{
    SnakesAndLadders* snakesAndLadders = new SnakesAndLadders(3);
    snakesAndLadders->GetDetails();
    snakesAndLadders->Play();
    delete snakesAndLadders;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

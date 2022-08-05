#pragma once
#include<iostream>
#include<vector>
#include"ladders.h"
#include"Snake.h"
using namespace std;
class Board {
	std::vector<Ladder>ladder;
	std::vector<Snake>snake;
public:
	Board();
	vector<Ladder> getLadders();
	vector<Snake>getSnakes();
	bool checkIfLadderFound(int position,  int& temp);
	bool checkIfSnakeFound(int position, int& temp);
};

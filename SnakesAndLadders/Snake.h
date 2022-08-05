#pragma once
#include<iostream>
class Snake {
	int start;
	int end;
public:
	Snake(int start, int end);
	int getStart();
	int getEnd();
};
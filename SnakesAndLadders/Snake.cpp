#include"Snake.h"
Snake::Snake(int start, int end)
{
	this->start = start;
	this->end = end;
}

int Snake::getStart() {
	return start;
}
int Snake::getEnd() {
	return end;
}
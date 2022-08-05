#include"ladders.h"
Ladder::Ladder(int start, int end)
{
	this->start = start;
	this->end = end;
}

int Ladder::getStart() {
	return start;
}
int Ladder::getEnd() {
	return end;
}
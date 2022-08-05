#include"Board.h"
#include <chrono>
Board::Board() {
	for (int i = 0; i < 4; i++)
	{
		auto millisec_since_epoch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
		auto sec_since_epoch = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();
		int start = millisec_since_epoch % 100;
		int end = sec_since_epoch % 100;
		if (start < end)
		{
			start = start + end;
			end = start - end;
			start = start - end;
		}
		Snake* s = new Snake(start, end);
		snake.push_back(*s);
	}
	for (int i = 0; i < 4; i++)
	{
		auto millisec_since_epoch = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
		auto sec_since_epoch = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();

		int start = millisec_since_epoch % 100;
		int end = sec_since_epoch % 100;
		if (start > end)
		{
			start = start + end;
			end = start - end;
			start = start - end;
		}
		Ladder* s = new Ladder(start, end);
		ladder.push_back(*s);
	}
}

vector<Ladder> Board::getLadders() {
	return ladder;
}
vector<Snake>  Board::getSnakes() {
	return snake;
}

bool Board::checkIfLadderFound(int position, int& temp) {
	for (auto it = ladder.begin(); it != ladder.end(); it++)
	{
		if ((*it).getStart() == position)
		{
			temp = (*it).getEnd();
			return true;
		}
	}
	return false;
}

bool Board::checkIfSnakeFound(int position, int& temp) {
	for (auto it = snake.begin(); it != snake.end(); it++)
	{
		if ((*it).getStart() == position)
		{
			temp = (*it).getEnd();
			return true;
		}
	}
	return false;
}
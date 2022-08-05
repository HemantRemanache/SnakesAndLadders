#include"Players.h"
Players::Players(int pid)
{
	myturn = false;
	position = 0;
	id = pid;
}

Players::~Players()
{
}

void Players::SetPosition(int pos) {
	position = pos;
}

int Players::GetPosition() {
	return position;
}

int Players::getid() {
	return id;
}
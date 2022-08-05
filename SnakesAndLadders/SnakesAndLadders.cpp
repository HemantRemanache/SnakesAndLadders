#include"SnakesAndLadders.h"
SnakesAndLadders::SnakesAndLadders(int playercount = 1) {
	for (int i = 0; i < playercount; i++)
	{
		Players* p = new Players(i);
		players.push_back(*p);
	}
	dice = new Dice();
	board = new Board();
	playerCount = playercount;
}

void SnakesAndLadders::Play() {
	Players p1 = players[0];
	while (p1.GetPosition() < 100)
	{

		int currentplayerpos = p1.GetPosition();
		cout << "\n\n Current Player : " << p1.getid() << "\n";
		cout << "Positioned at :" << currentplayerpos << "\n";
		cout << "Press Spacebar to roll the dice\n";
		getchar();
		int dicevalue = dice->ThrowDice();
		cout << "\t Dice value :" << dicevalue;

		if ((currentplayerpos + dicevalue) > 100)
		{
			p1 = GetNextPlayer(p1);
		}
		else if ((currentplayerpos + dicevalue) < 100)
		{
			int temp = -1;
			int& tempvalue = temp;
			bool ladderfound = board->checkIfLadderFound(currentplayerpos + dicevalue, tempvalue);
			if (ladderfound)
			{
				cout << "Whooop...!!!!" << tempvalue - (currentplayerpos + dicevalue) << " places jump\n";
				p1.SetPosition(tempvalue);
				cout << "\t New Position :" << tempvalue;
				continue;
			}
			else
			{
				bool snakefound = board->checkIfSnakeFound(currentplayerpos + dicevalue, tempvalue);
				if (snakefound)
				{
					cout << "Shiiiittt...!!!!" << (currentplayerpos + dicevalue) - tempvalue << " places gone\n";
					p1.SetPosition(tempvalue);
					cout << "\t New Position :" << tempvalue;
				}
				else
				{
					cout << "\t New Position :" << currentplayerpos + dicevalue;
					p1.SetPosition(currentplayerpos + dicevalue);
				}
			}
			if (6 == dicevalue)
				continue;
			p1 = GetNextPlayer(p1);
		}
		else
		{
			cout << "\n\n \t\t Won\n\n";
			return;

		}

	}
}

void SnakesAndLadders::GetDetails() {
	vector<Ladder>ladder = board->getLadders();
	vector<Snake>snake = board->getSnakes();
	int count = 1;
	for (auto i = ladder.begin(); i != ladder.end(); i++)
	{
		cout << "\n ladder " << count++ << "\t";
		cout << (*i).getStart() << "\t" << (*i).getEnd();
	}
	count = 1;
	for (auto i = snake.begin(); i != snake.end(); i++)
	{
		cout << "\n Snake " << count++ << "\t";
		cout << (*i).getStart() << "\t" << (*i).getEnd();
	}
}

Players SnakesAndLadders::GetNextPlayer(Players p1) {
	std::vector<Players>::iterator itr = std::find(players.begin(), players.end(), p1);
	int dist = std::distance(players.begin(), itr);
	players[dist] = p1;
	if (dist == (players.size() - 1))
	{
		return *(players.begin());
	}
	else
	{
		return *(players.begin() + dist + 1);
	}
}
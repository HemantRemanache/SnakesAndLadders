#pragma once
class Players
{
public:
	bool operator == (const Players& p1) {
		if (this->id == p1.id)
			return true;
		else
			return false;
	}
	Players(int pid);
	~Players();
	bool getmyturn() {
		return myturn;
	}
	void setmyturn(bool myturnvalue) {
		myturn = myturnvalue;
	}
	void SetPosition(int);
	int GetPosition();
	int getid();
private:
	bool myturn;
	int position;
	int id;
};

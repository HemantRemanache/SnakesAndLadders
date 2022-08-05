

#include"Dice.h"
Dice::Dice() {
	dicevalue = 0;
}
int Dice::ThrowDice() {
	auto sec_since_epoch = chrono::duration_cast<chrono::seconds>(chrono::system_clock::now().time_since_epoch()).count();

	dicevalue = (sec_since_epoch % 6)+1;
	return dicevalue;
}

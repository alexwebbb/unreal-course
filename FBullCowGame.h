#pragma once
#include<string>

class FBullCowGame
{
public:
	void Reset(int WordLength);
	int GetMaxTries(); // ???
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string);


private:
	int MyCurrentTry();
	int MyMaxTries(); // what does this mean???
};
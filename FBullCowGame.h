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
	int MyCurrentTry = 0;
	int MyMaxTries = 5; 
};
#pragma once
#include<string>

class FBullCowGame
{
public:
	FBullCowGame();

	int GetMaxTries() const; // oh it really is just a getter
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(int WordLength, int MaxTries);
	bool CheckGuessValidity(std::string);


private:
	int MyCurrentTry;
	int MyMaxTries; 
	int MyWordLength;
};
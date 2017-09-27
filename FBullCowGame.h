#pragma once
#include<string>

using FString = std::string;
using int32 = int;


class FBullCowGame
{
public:
	FBullCowGame();

	int GetMaxTries() const; // oh it really is just a getter
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(int32 WordLength, int32 MaxTries);
	bool CheckGuessValidity(FString);


private:
	int MyCurrentTry;
	int MyMaxTries; 
	int MyWordLength;
};
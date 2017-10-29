#pragma once
#include<string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();

	int GetMaxTries() const; // oh it really is just a getter
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString);
	FBullCowCount SubmitGuess(FString);

private:
	int MyCurrentTry;
	int MyMaxTries; 
	int MyWordLength;
	FString MyHiddenWord;
};
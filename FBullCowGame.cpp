#include "FBullCowGame.h"


FBullCowGame::FBullCowGame()
{
	this->Reset(6, 8);
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset(int WordLength, int MaxTries)
{

	MyMaxTries = MaxTries;
	MyWordLength = WordLength;
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

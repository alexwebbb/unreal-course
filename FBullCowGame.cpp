#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame()
{
	this->Reset();
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 WORD_LENGTH = 6;
	constexpr int32 MAX_TRIES = 4;
	const FString HIDDEN_WORD = "potato";

	MyMaxTries = MAX_TRIES;
	MyWordLength = WORD_LENGTH;
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}


// handles valid guess, increment turn # and return count
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment turn number
	MyCurrentTry++;

	// initialize return variable
	BullCowCount BullCowCount;
	
	// loop through letter of guess
	


	// and compare each letter to word


	return BullCowCount;
}

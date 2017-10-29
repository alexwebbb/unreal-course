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

	MyWordLength = WORD_LENGTH;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
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
FBullCowCount FBullCowGame::SubmitGuess(FString ValidGuess)
{

	

	// increment turn number
	MyCurrentTry++;

	// initialize return variable
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = ValidGuess.length();


	// loop through letter of guess
	for (int32 i = 0; i < HiddenWordLength; i++)
	{

		bool IsBull = false;
		bool IsCow = false;

		// compare each letter to word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			// if there is a match then
			// extra conditions til they fix it in the course
			if (i < HiddenWordLength &&
				j < GuessLength &&
				MyHiddenWord[i] == ValidGuess[j])
			{
				// if index matches as well then Bull
				if (i == j)
				{
					IsBull = true;
					
				}
				// if not then Cow
				else
				{
					IsCow = true;
				}
			}
		}

		if (IsBull)
		{
			BullCowCount.Bulls++;
		}
		else if (IsCow)
		{
			BullCowCount.Cows++;
		} 
	}


	return BullCowCount;
}

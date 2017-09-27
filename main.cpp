#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "FBullCowGame.h"


// using namespace std::this_thread; // sleep_for, sleep_until
// using namespace std::chrono; // nanoseconds, system_clock, seconds


using FText = std::string;
using int32 = int;

void Say(FText phrase, int32 delay = 1500);
void PlayGame();
bool PlayAgainQuery();
void PrintIntro();
FText GetGuess();

FBullCowGame BCGame;
constexpr int32 WORD_LENGTH = 6;
constexpr int32 MAX_TRIES = 8;

int main(int32 argc, char **argv) 
{

	PrintIntro();
	PlayGame();
	
	return 0;
}

void PlayGame()
{
	BCGame.Reset(WORD_LENGTH, MAX_TRIES);

	int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";
	bool Continue = true;
	
	do
	{
		// TODO  will convert to a while loop later
		for (int32 i = 0; i < MaxTries; i++)
		{

			Guess = GetGuess();
			std::cout << "Your guess is " << Guess << "?? Wild" << std::endl;
			// TODO check validity of guess
		}
		// TODO Give results of game
		Continue = PlayAgainQuery();
	}
	while (Continue == true);
}

bool PlayAgainQuery()
{
	FText Res = "";
	FText Comebacks[6] = { "What was that?", "Come again?", 
		"Pardon?", "Look... I'm a computer", "ok....", "....." };
	int32 itt = 0;



	Say("Do you want to play again?");
	while (true)
	{
		itt++;
		std::cout << "(Type 'y' or 'n') ";
		std::getline(std::cin, Res);
		if (Res[0] == 'y' || Res[0] == 'Y')
		{
			Say("Sweet", 400);
			return true;
		}
		else if (Res[0] == 'n' || Res[0] == 'N')
		{
			Say("No way!", 100);
			return false;
		}
		else
		{
			Say(Comebacks[itt%6], 200);
		}
	}
}

void Say(FText phrase, int32 delay)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	std::cout << phrase << std::endl;
}

void PrintIntro()
{
	Say("Lets play some bulls and COWS yall!", 2000);
	Say("I got a secret word, yall all gotta try and guess it.");
	Say("Heh, I'll make it easy for ya, its " + std::to_string(WORD_LENGTH) + " long,");
	Say("an' I ain' use any letter more than once.");

	return;
}

FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	if (CurrentTry > 1)
	{
		std::cout << "\nTry " << CurrentTry << std::endl;
	}
	for (size_t i = 0; i < 5; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
		std::cout << ".";
	}
	std::cout << "Gimme that guess! \n(Hint: Enter your guess) ";
	std::getline(std::cin, Guess);
	return Guess;
}
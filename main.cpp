#include <iostream>
#include <string>
#include <chrono>
#include <thread>


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


void Say(std::string phrase, int delay = 1500);
void PlayGame();
bool PlayAgainQuery();
void PrintIntro();
std::string GetGuess();

int main(int argc, char **argv) 
{
	PrintIntro();
	PlayGame();
	
	return 0;
}

void PlayGame()
{
	std::string Guess = "";
	bool Continue = true;

	do
	{
		Guess = GetGuess();
		std::cout << "Your guess is " << Guess << "?? Wild" << std::endl;

		Continue = PlayAgainQuery();
	}
	while (Continue == true);
	
}

bool PlayAgainQuery()
{
	std::string Res = "";
	std::string Comebacks[6] = { "What was that?", "Come again?", 
		"Pardon?", "Look... I'm a computer", "ok....", "....." };
	int itt = 0;



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

void Say(std::string phrase, int delay)
{
	sleep_for(milliseconds(delay));
	std::cout << phrase << std::endl;
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;

	Say("Lets play some bulls and COWS yall!", 2000);
	Say("I got a secret word, yall all gotta try and guess it.");
	sleep_for(milliseconds(1500));
	std::cout << "Heh, I'll make it easy for ya, its " << WORD_LENGTH << " long,\n";
	Say("an' I ain' use any letter more than once.");

	return;
}

std::string GetGuess()
{
	std::string Guess = "";

	for (size_t i = 0; i < 5; i++)
	{
		sleep_for(milliseconds(400));
		std::cout << ".";
	}
	std::cout << "Gimme that guess! \n(Hint: Enter your guess) ";
	std::getline(std::cin, Guess);
	return Guess;
}
#include <iostream>
#include <string>
#include <chrono>
#include <thread>



using namespace std;
using namespace this_thread; // sleep_for, sleep_until
using namespace chrono; // nanoseconds, system_clock, seconds


void Say(string phrase, int delay = 1500);
void PlayGame();
bool PlayAgainQuery();
void PrintIntro();
string GetGuess();

int main(int argc, char **argv) 
{
	PrintIntro();
	PlayGame();
	
	return 0;
}

void PlayGame()
{
	string Guess = "";
	
	Guess = GetGuess();
	cout << "Your guess is " << Guess << "?? Wild" << endl;
	
	PlayAgainQuery();

	
}

bool PlayAgainQuery()
{
	string Res = "";

	Say("Do you want to play again?");
	while (true)
	{
		cout << "(Type 'y' or 'n') ";
		getline(cin, Res);
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
			Say("What was that?", 200);
		}
	}
}

void Say(string phrase, int delay)
{
	sleep_for(milliseconds(delay));
	cout << phrase << endl;
}

void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;

	Say("Lets play some bulls and COWS yall!", 2000);
	Say("I got a secret word, yall all gotta try and guess it.");
	sleep_for(milliseconds(1500));
	cout << "Heh, I'll make it easy for ya, its " << WORD_LENGTH << " long,\n";
	Say("an' I ain' use any letter more than once.");

	return;
}

string GetGuess()
{
	string Guess = "";

	for (size_t i = 0; i < 5; i++)
	{
		sleep_for(milliseconds(400));
		cout << ".";
	}
	cout << "Gimme that guess! \n(Hint: Enter your guess) ";
	getline(cin, Guess);
	return Guess;
}
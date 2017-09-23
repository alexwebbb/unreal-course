#include <iostream>
#include <string>
#include <chrono>
#include <thread>


using namespace std;
using namespace this_thread; // sleep_for, sleep_until
using namespace chrono; // nanoseconds, system_clock, seconds


void say(string phrase, int delay = 1500) {
	sleep_for(milliseconds(delay));
	cout << phrase << endl;
}

int main(int argc, char **argv) {

	constexpr int WORD_LENGTH = 5;
	string Guess = "";
	
	say("Lets play some bulls and COWS yall!", 2000);
	say("I got a secret word, yall all gotta try and guess it.");
	sleep_for(milliseconds(1500));
	cout << "Heh, I'll make it easy for ya, its " << WORD_LENGTH << " long, " << endl;
	say("an' I ain' use any letter more than once.");
	for (size_t i = 0; i < 3; i++)
	{
		sleep_for(milliseconds(1500));
		cout << ".";
	}
	cout << "Gimme that guess! (Hint: Enter your guess) ";
	getline(cin, Guess);
	Guess.resize(WORD_LENGTH);
	cout << "Your guess is " << Guess << "?? Wild" << endl;

	return 0;

}
#include <iostream>
#include <string>
#include <chrono>
#include <thread>


using namespace std;
using namespace this_thread; // sleep_for, sleep_until
using namespace chrono; // nanoseconds, system_clock, seconds


int main(int argc, char **argv) {

	constexpr int WORD_LENGTH = 5;
	string Guess = "";
	
	sleep_for(milliseconds(8000));
	cout << "Lets play some bulls and COWS yall!" << endl;
	sleep_for(milliseconds(1500));
	cout << "I got a secret word, yall all gotta try and guess it." << endl;
	sleep_for(milliseconds(1500));
	cout << "Heh, I'll make it easy for ya, its " << WORD_LENGTH << " long," << endl;
	sleep_for(milliseconds(1500));
	cout << "an' I ain' use any letter more than once." << endl;
	for (size_t i = 0; i < 3; i++)
	{
		sleep_for(milliseconds(1500));
		cout << ".";
	}
	cout << "Gimme that guess! (Hint: Enter your guess) ";
	cin >> Guess;
	cout << "Your guess is " << Guess << "?? Wild" << endl;

	return 0;

}
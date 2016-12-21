#include "codeWord.h"
#include <string>
#include <time.h>

using namespace std;

const int max_number_of_guesses = 12;
extern const int number_of_code_pegs; 

int main()
{
	char ans;
	string input;
	 
	do {		
		srand(time(NULL));		// Reseed the RNG
		hiddenCode hCode;		// Hidden code object
		hCode.generateCode();	// Generate code
		cout << "New code is generated consisting of " << number_of_code_pegs << " pegs." << endl;
		cout << "Each peg is a letter from a-f." << endl;
		cout << "Try breaking the code:" << endl;
		cout << "- Correct letter, but not in the right place, gives a M (for Match)." << endl;
		cout << "- Exact match gives an E (for Exact match)." << endl;

		guessCode guesses[max_number_of_guesses]; // Array holding all guess objects
		int noOfGuesses = 0;
		int displayCtn = 0;
		int exactMatch = 0;
		int match = 0;
		while (noOfGuesses < max_number_of_guesses)
		{
			/*
			try
			{*/
				guesses[noOfGuesses].enterCode();	// Ask user to enter a guess
			/*}
			catch(guessCode::whiteSpaces)
			{
				cout << "Error: the guess contains whitespaces, periods or commas" << endl;
			}
			catch(guessCode::guessError)
			{
				cout << "Error: the guess does not consist of " << number_of_code_pegs << " letters" << endl;
			}*/


			// Compare guess to code			
			exactMatch = guesses[noOfGuesses].exactCompare(guesses[noOfGuesses], hCode);	// Find exact matches
			match = guesses[noOfGuesses].compareCodes(guesses[noOfGuesses], hCode);		// Find matches

			guesses[noOfGuesses].updateKeys(exactMatch, match);

			// Display guess and eventual key pegs
			cout << "\nGuess no.: " << "\t" << "Guess:" << "\t\t" << "Key pegs:" << endl;
			displayCtn = noOfGuesses + 1;
			while(displayCtn > 0)
			{
				cout << displayCtn << "\t\t";
				guesses[displayCtn-1].displayGuess();
				displayCtn--;	
				cout << endl;
			}
						
			noOfGuesses++;
			
			if (exactMatch == number_of_code_pegs)	
			{
				cout << "Congratulations! You won in " << noOfGuesses << " guesses" << endl;
				break;
			}

			if (noOfGuesses == max_number_of_guesses)
			{
				cout << "Game over: You haven't guessed the code in less than " << max_number_of_guesses << " turns" << endl;
			}
		}

		hCode.displayCode();

		cout << "Play again (y/n)?: ";
		cin >> ans;
		cout << endl;
	} while ( ans != 'n' );

	return 0;
}
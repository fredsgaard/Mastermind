#include <iostream>
#include "codeWord.h"

int code::exactCompare(code guess, code secret)
{
	int exactMatches = 0;
	for(int j = 0; j < number_of_code_pegs; j++)
	{
		if( guess.codeWord[j] == secret.codeWord[j] )
			exactMatches++;
	}		
	return exactMatches;
}

int code::compareCodes(code guess, code secret)
{
	string guessStr = guess.codeWord;		// Temp guess string
	string secretStr = secret.codeWord;		// Temp secret string
	int iterations = number_of_code_pegs;
	int exactMatches = 0;
	// Find Exact matches and erase exact matching letters
	while(iterations != 0)
	{
	iterations--;
	if( guessStr[iterations] == secretStr[iterations] ) 
		{
			guessStr.erase(iterations,1);
			secretStr.erase(iterations,1);
			exactMatches++;			
		}
	}

	// Find matches
	iterations = secretStr.length();
	size_t pos;
	int matches = 0;
	do{
		for(unsigned int guessIdx = 0; guessIdx < secretStr.length(); guessIdx++)
		{
			pos = secretStr.find_first_of(guessStr[guessIdx]);
			if(pos <= secretStr.length())
			{
				matches++;
				guessStr.erase(guessIdx,1);
				secretStr.erase(pos,1);
				break;
			}			
		}
		iterations--;
	}while(iterations != 0);

	return matches;
}

void hiddenCode::displayCode()
{
	cout << "The secret code is:" << "\t";
	for(int j = 0; j < number_of_code_pegs; j++)
	{
		cout << codeWord[j] << " "; 
	}	
	cout << endl;
}

void guessCode::enterCode()
{
	string input;
	cout << "\nEnter your guess and press Enter:" << endl; 	
	cin >> input;
	/*if(input.length() != number_of_code_pegs)
	{
		throw guessError();
	}

	if(input.find(' '))
	{
		throw whiteSpaces();
	}*/


	codeWord = input;
}

void guessCode::updateKeys(int exactMatches, int matches)
{
	int indexKeys = 0;
	while(exactMatches > 0)
	{
		keys[indexKeys] = 'E';
		indexKeys++;
		exactMatches--;
	}

	while(matches > 0)
	{
		keys[indexKeys] = 'M';
		indexKeys++;
		matches--;
	}
}

void guessCode::displayGuess()
{
	for(int j = 0; j < number_of_code_pegs; j++)
	{
		cout << codeWord[j] << " "; 
	}	

	cout << "\t";

	for(int j = 0; j < number_of_code_pegs; j++)
	{
		cout << keys[j] << " "; 
	}	
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

const int number_of_code_pegs = 4;
//const int number_of_colours = 6;
const char codePegs[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

class code
{
private:

protected:	
	string codeWord;		// codeWord is protected to allow access from child classes

public:
	code()
		{}					// Constructor;

	int exactCompare(code guess, code secret);
	int compareCodes(code guess, code secret);

	~code()					// Destructor
		{}
};

class hiddenCode : public code
{	
private:	

public:	
	void generateCode()
	{
		for(int j = 0; j < number_of_code_pegs; j++)
		{
			codeWord.push_back(codePegs[ rand() % 5 ]);
		} 
	}	
	void displayCode();
};

class guessCode : public code
{
private:
	char keys[number_of_code_pegs];

public:
	guessCode()		// Constructor: Initializes the keys to white spaces
	{ 
		for(int j = 0; j < number_of_code_pegs; j++)
		{
			keys[j] = ' '; 
		}
	}
			
	void enterCode();
	void updateKeys(int exactMatches, int matches);
	void displayGuess();
	/*
	class whiteSpaces		// Exception class: white spaces in guess
	{

	};

	class guessError		// Exception class: guess longer than number_of_code_pegs
	{

	};*/
};
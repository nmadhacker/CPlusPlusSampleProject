/*
//  main.cpp
//  ExampleProgram
//
//  Created by nMaD on 9/27/17.
//  Copyright © 2017 nMaD. All rights reserved.
*/

#include <iostream>
#include "MyCustomClass.h"

using int32 = int;
using FText = std::string;

using namespace std;

struct superStruct {
    int32 name;
};

MyCustomClass instance;

void PrintIntro();
void PlayGame();
FText GuetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

void PlayGame()
{
	superStruct myStruct;
	superStruct *ptr;
    ptr = &myStruct;

	myStruct.name = 5;
	ptr->name = 10;
    
    instance.Reset();
	int32 maxTries = instance.GetMaxTries();

	cout << myStruct.name << "\n\n";

	string Guess = "";
    
	while (!instance.IsGameWon() && instance.GetCurrentTry() <= instance.GetMaxTries())
	{
		Guess = GuetValidGuess();                
        
        FBullCowCount BullCowCount = instance.SubmitValidGuess(Guess);
        
        cout << "Bulls = " << BullCowCount.Bulls;
        cout << ". Cows = "<< BullCowCount.Cows << endl;
	}
    
    PrintGameSummary();
}

void PrintGameSummary()
{
    cout << "You " << (instance.IsGameWon() ? "Won" : "Lost") << "!!\n";
}

bool AskToPlayAgain()
{
	cout<<"Do you want to play again? (y/n): ";
    int32 answer = std::getchar();
    return answer == 'y';
}

// entry point of this app
int main()
{
	bool playAgain = true;
	do
	{
		PrintIntro();
		PlayGame();
		playAgain = AskToPlayAgain();
	} while (playAgain);

	return 0;
}

void PrintIntro()
{
    cout << "Welcome to my app" << endl;
    cout << "Today's value is: " << instance.GetHiddenWordLength() << "\n";
}

// loop until get a valid guess
FText GuetValidGuess()
{
    EWordStatus Status = EWordStatus::Not_Isogram;
    string ToReturn;
    
    do
    {
        cout << "Try" << instance.GetCurrentTry() << ", Two and two are? ";
        
        getline(cin,ToReturn);
        
        Status = instance.CheckGuessValidity(ToReturn);
        
        switch (Status) {
            case EWordStatus::Wrong_Length:
                cout << "Please enter a " << instance.GetHiddenWordLength() << " letter word";
                break;
            case EWordStatus::Not_Isogram:
                cout << "Please enter a word without repeating letters";
                break;
            case EWordStatus::Not_Lowercase:
                cout << "Please enter all lowercase letters";
                break;
            default:
                break;
        }
        cout << endl;
    } while(Status != EWordStatus::OK); // keep looping until we get a valid value
    
    return ToReturn;
}

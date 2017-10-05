/*
//  main.cpp
//  ExampleProgram
//
//  Created by nMaD on 9/27/17.
//  Copyright © 2017 nMaD. All rights reserved.
*/

#include <iostream>
#include "main.h"


using int32 = int;
using FText = std::string;

using namespace std;

struct superStruct {
    int32 name;
};

MyCustomClass instance;

void PrintIntro();
void PlayGame();
FText GetValueFromLine();
bool AskToPlayAgain();

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

	string MyString = "";
	int32 index = 0;
	while (index < maxTries)
	{
		cout << "Try" << instance.GetCurrentTry() << ", Two and two are? ";
		MyString = GetValueFromLine();
		cout << "You entered: " << MyString << endl;
		index++;
	}
}

bool AskToPlayAgain()
{
	return false;
}

// entry point of this app
int main()
{
	bool playAgain = false;
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

FText GetValueFromLine()
{
    string ToReturn;
    getline(cin,ToReturn);
    return  ToReturn;
}

// ==============================================================

MyCustomClass::MyCustomClass()
{
    Reset();
}

int32 MyCustomClass::GetCurrentTry() const { return MyCurrentTry; }
int32 MyCustomClass::GetMaxTries() const { return MyMaxTries; }
int32 MyCustomClass::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool MyCustomClass::IsGameWon() const { return false; }
void MyCustomClass::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
    
    constexpr int32 INIT_TRY = 1;
    MyCurrentTry = INIT_TRY;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
}

FBullCowCount MyCustomClass::CheckAnswer(FString Guess)
{
    FBullCowCount toReturn;
    
    int32 HiddenWordLength = MyHiddenWord.length();
    for(int32 i = 0; i < HiddenWordLength; ++i)
    {
        for(int32 j = 0; j < Guess.length(); ++j)
        {
            if (Guess[j] == MyHiddenWord[i])
            {
                if (i == j)
                {
                    toReturn.Bulls++;
                }
                else
                {
                    toReturn.Cows++;
                }
            }
        }
    }
    
    return toReturn;
}

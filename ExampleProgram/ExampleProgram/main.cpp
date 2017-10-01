//
//  main.cpp
//  ExampleProgram
//
//  Created by nMaD on 9/27/17.
//  Copyright © 2017 nMaD. All rights reserved.
//

#include <iostream>
#include <string>
#include "main.h"

using namespace std;

struct superStruct {
    int name;
};

MyCustomClass instance;

void PlayGame()
{
	superStruct myStruct;
	superStruct *ptr; ptr = &myStruct;

	myStruct.name = 5;
	ptr->name = 10;

	int maxTries = instance.GetMaxTries();

	cout << myStruct.name << "\n\n";

	string MyString = "";
	int index = 0;
	while (index < maxTries)
	{
		cout << "Try" << instance.GetCurrentTry() << ", Two and two are? ";
		MyString = instance.GetValueFromLine();
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
		instance.PrintIntro();
		PlayGame();
		playAgain = AskToPlayAgain();
	} while (playAgain);

	return 0;
}

// ==============================================================

int MyCustomClass::GetCurrentTry() const { return MyCurrentTry; }
bool MyCustomClass::IsGameWon() const
{
	return false;
}
void MyCustomClass::Reset()
{
}

int MyCustomClass::GetMaxTries() const { return MyMaxTries; }

void MyCustomClass::PrintIntro() const
{
    constexpr int MY_CONSTANT = 10;
    cout << "Welcome to my app" << endl;
    cout << "Today's value is: " << MY_CONSTANT << "\n";
}

string MyCustomClass::GetValueFromLine()
{
    string ToReturn;
    getline(cin,ToReturn);
    return  ToReturn;
}
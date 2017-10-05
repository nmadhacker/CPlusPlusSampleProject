//
//  main.h
//  ExampleProgram
//
//  Created by nMaD on 9/27/17.
//  Copyright © 2017 nMaD. All rights reserved.
//

#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

class MyCustomClass
{

public:
	
    MyCustomClass(); // Constructor
    
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	
    void Reset();
    FBullCowCount CheckAnswer(FString Guess);
    
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;
    FString MyHiddenWord;
};

//
//  MyCustomClass.h
//  ExampleProgram
//
//  Created by nMaD on 9/27/17.
//  Copyright © 2017 nMaD. All rights reserved.
//

#pragma once
#include <string>
#include <map>
#define TMap std::map

using int32 = int;
using FString = std::string;

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EWordStatus
{
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

enum class EResetStatus
{
    No_Hidden_Word,
    OK
};

class MyCustomClass
{

public:
	
    MyCustomClass(); // Constructor
    
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
    FString GetHiddenWord() const;
    int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	
    void Reset(int32 difficulty);
    EWordStatus CheckGuessValidity(FString Guess) const;
    FBullCowCount SubmitValidGuess(FString Guess);
    
private:
	int32 MyCurrentTry;
    int32 MyCurrentDifficulty;
    TMap<int32,FString> HiddenWords;
    int32 MinWordLength, MaxWordLength;
    bool bIsGameWon;
    
    bool IsIsogram(FString Guess) const;
    bool IsLowerCase(FString Guess) const;
};

//
//  MyCustomClass.cpp
//  ExampleProgram
//
//  Created by nMaD on 10/5/17.
//  Copyright © 2017 nMaD. All rights reserved.
//

#include "MyCustomClass.h"
#include <map>
#define TMap std::map

MyCustomClass::MyCustomClass()
{
    Reset(3);
}

int32 MyCustomClass::GetCurrentTry() const { return MyCurrentTry; }
FString MyCustomClass::GetHiddenWord() const { return HiddenWords.find(MyCurrentDifficulty)->second; }
int32 MyCustomClass::GetHiddenWordLength() const { return GetHiddenWord().length(); }
bool MyCustomClass::IsGameWon() const { return bIsGameWon; }

int32 MyCustomClass::GetMaxTries() const
{
    TMap<int32,int32> WordLengthToMaxTries { {3,5},{4,6},{5,7},{6,10},{7,12} };
    return WordLengthToMaxTries[GetHiddenWordLength()];
}

void MyCustomClass::Reset(int32 difficulty)
{
    constexpr int32 INIT_TRY = 1;
    constexpr int32 MIN_WORD_LENGTH = 3;
    constexpr int32 MAX_WORD_LENGTH = 7;
    
    MyCurrentTry = INIT_TRY;
    MinWordLength = MIN_WORD_LENGTH;
    MaxWordLength = MAX_WORD_LENGTH;        
    
    HiddenWords = { {3,"alt"}, {4,"plan"}, {5,"plane"}, {6,"planet"}, {7,"planets"} };
    
    FString tree = HiddenWords[3];
    
    
    MyCurrentDifficulty = difficulty < MinWordLength ? MinWordLength : difficulty > MaxWordLength ? MaxWordLength : difficulty;
    
    bIsGameWon = false;
}

EWordStatus MyCustomClass::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess))
    {
        return EWordStatus::Not_Isogram;
    }
    else if (!IsLowerCase(Guess)) // if the guess isn't all lowercase,
    {
        return EWordStatus::Not_Lowercase; // TODO: Write method
    }
    else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
    {
        return EWordStatus::Wrong_Length;
    }
    else
    {
        return EWordStatus::OK;
    }
}

FBullCowCount MyCustomClass::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount toReturn;
    
    int32 HiddenWordLength = GetHiddenWordLength();
    for(int32 i = 0; i < HiddenWordLength; ++i)
    {
        for(int32 j = 0; j < Guess.length(); ++j)
        {
            if (Guess[j] == GetHiddenWord()[i])
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
    
    bIsGameWon = toReturn.Bulls == HiddenWordLength;
    
    return toReturn;
}

bool MyCustomClass::IsIsogram(FString Guess) const
{
    // 0 and 1 letter words are considered isograms
    if (Guess.length() == 0) { return true; }
    
    TMap<char, bool> letters;
    for(auto letter : Guess)
    {
        letter = tolower(letter); // handle uppercase and lowercase
        if (letters[letter])
        {
            return false;
        }
        letters[letter] = true;
    }
    return true;
}

bool MyCustomClass::IsLowerCase(FString Guess) const
{
    if (Guess.length() == 0) { return true; }
    
    for(auto letter : Guess)
    {
        if (!islower(letter))
        {
            return false;
        }
    }
    
    return true;
}
